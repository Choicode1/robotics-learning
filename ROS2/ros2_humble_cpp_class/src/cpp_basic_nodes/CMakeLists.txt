cmake_minimum_required(VERSION 3.8)
project(cpp_basic_nodes)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  # the following line skips the linter which checks for copyrights
  # comment the line when a copyright and license is added to all source files
  set(ament_cmake_copyright_FOUND TRUE)
  # the following line skips cpplint (only works in a git repo)
  # comment the line when this package is in a git repo and when
  # a copyright and license is added to all source files
  set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()

# ---------------------------------------------------------
# simple_node 실행 파일 생성
# ---------------------------------------------------------
add_executable(cpp_talker src/cpp_talker.cpp)

# simple_node가 사용할 ROS2 의존성 연결
ament_target_dependencies(cpp_talker
  rclcpp
  std_msgs
)

# ros2 run으로 실행할 수 있도록 install 경로 등록
install(TARGETS
  cpp_talker
  DESTINATION lib/${PROJECT_NAME}
)

# ---------------------------------------------------------
# cpp_listener 실행 파일 생성
# ---------------------------------------------------------
add_executable(cpp_listener src/cpp_listener.cpp)

# cpp_listener가 사용할 ROS2 의존성 연결
ament_target_dependencies(cpp_listener
  rclcpp
  std_msgs
)

# ros2 run으로 실행할 수 있도록 install 경로 등록
install(TARGETS
  cpp_listener
  DESTINATION lib/${PROJECT_NAME}
)

ament_package()
