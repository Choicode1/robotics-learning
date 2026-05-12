"""
map_actuator_to_qpos.py

목적:
- actuator를 하나씩 움직여 보고 어떤 qpos가 크게 변하는지 확인한다.
- actuator와 joint/qpos의 대응 관계를 초보자도 감각적으로 이해한다.

주의:
- 이것은 정밀한 동역학 분석이 아니라 교육용 관찰 코드이다.
"""

from pathlib import Path
import mujoco
import numpy as np


def main():
    project_root = Path(__file__).resolve().parents[1]

    xml_path = (
        project_root
        / "mujoco_menagerie"
        / "franka_emika_panda"
        / "scene.xml"
    )

    model = mujoco.MjModel.from_xml_path(str(xml_path))

    print("Number of actuators:", model.nu)
    print("Number of qpos:", model.nq)

    if model.nu == 0:
        print("이 모델에는 actuator가 없습니다.")
        return

    for actuator_id in range(model.nu):
        data = mujoco.MjData(model)

        qpos_before = data.qpos.copy()

        ctrl_min = model.actuator_ctrlrange[actuator_id][0]
        ctrl_max = model.actuator_ctrlrange[actuator_id][1]

        command = 0.1
        command = float(np.clip(command, ctrl_min, ctrl_max))

        data.ctrl[:] = 0.0
        data.ctrl[actuator_id] = command

        for _ in range(200):
            mujoco.mj_step(model, data)

        qpos_after = data.qpos.copy()
        diff = np.abs(qpos_after - qpos_before)

        top_indices = np.argsort(diff)[::-1][:5]

        actuator_name = mujoco.mj_id2name(
            model,
            mujoco.mjtObj.mjOBJ_ACTUATOR,
            actuator_id
        )

        print("\n------------------------------")
        print(f"Actuator {actuator_id}: {actuator_name}")
        print(f"Command: {command}")
        print("Top changed qpos indices:")

        for idx in top_indices:
            print(f"  qpos_{idx}: diff={diff[idx]:.6f}")


if __name__ == "__main__":
    main()