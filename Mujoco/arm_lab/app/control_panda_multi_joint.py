"""
control_panda_multi_joint.py

목적:
- Panda 로봇팔의 여러 actuator를 동시에 부드럽게 움직인다.
- 각 actuator에 서로 다른 위상의 사인파 명령을 넣는다.
- 결과 영상을 저장한다.

주의:
- 여러 관절을 동시에 크게 움직이면 모델이 불안정해질 수 있다.
- 처음에는 작은 amplitude부터 시작한다.
"""

from pathlib import Path
import math

import imageio.v2 as imageio
import mujoco
import numpy as np


def get_first_camera_name(model: mujoco.MjModel) -> str | None:
    for camera_id in range(model.ncam):
        name = mujoco.mj_id2name(
            model,
            mujoco.mjtObj.mjOBJ_CAMERA,
            camera_id
        )
        if name:
            return name
    return None


def safe_amplitude(model: mujoco.MjModel, actuator_id: int) -> float:
    ctrl_min = model.actuator_ctrlrange[actuator_id][0]
    ctrl_max = model.actuator_ctrlrange[actuator_id][1]

    amp = 0.15 * min(abs(ctrl_min), abs(ctrl_max))
    amp = min(amp, 0.3)

    if amp <= 1e-6:
        amp = 0.1

    return amp


def main():
    project_root = Path(__file__).resolve().parents[1]

    xml_path = (
        project_root
        / "mujoco_menagerie"
        / "franka_emika_panda"
        / "scene.xml"
    )

    output_dir = project_root / "data"
    output_dir.mkdir(exist_ok=True)

    video_path = output_dir / "panda_multi_joint_control.mp4"

    model = mujoco.MjModel.from_xml_path(str(xml_path))
    data = mujoco.MjData(model)

    if model.nu == 0:
        raise RuntimeError("이 모델에는 actuator가 없습니다.")

    renderer = mujoco.Renderer(model, height=480, width=640)
    camera_name = get_first_camera_name(model)

    fps = 30
    duration_sec = 8
    total_frames = fps * duration_sec

    frames = []

    controlled_count = min(3, model.nu)

    print("Controlled actuator count:", controlled_count)

    for frame_idx in range(total_frames):
        t = frame_idx / fps

        data.ctrl[:] = 0.0

        for actuator_id in range(controlled_count):
            ctrl_min = model.actuator_ctrlrange[actuator_id][0]
            ctrl_max = model.actuator_ctrlrange[actuator_id][1]

            amp = safe_amplitude(model, actuator_id)
            phase = actuator_id * math.pi / 3.0

            command = amp * math.sin(2.0 * math.pi * 0.4 * t + phase)
            command = float(np.clip(command, ctrl_min, ctrl_max))

            data.ctrl[actuator_id] = command

        for _ in range(5):
            mujoco.mj_step(model, data)

        if camera_name:
            renderer.update_scene(data, camera=camera_name)
        else:
            renderer.update_scene(data)

        frame = renderer.render()
        frames.append(frame)

    imageio.mimsave(video_path, frames, fps=fps)
    renderer.close()

    print(f"Saved video: {video_path}")
    print("Multi-joint control completed successfully.")


if __name__ == "__main__":
    main()
