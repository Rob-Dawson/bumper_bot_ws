cmake_minimum_required(VERSION 3.8)
project(bumperbot_examples_cpp)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)
find_package(rcl_interfaces REQUIRED)
find_package(turtlesim REQUIRED)
# Include directories
include_directories(
  include
)

add_executable(simple_publisher src/publisher.cpp)
ament_target_dependencies(simple_publisher rclcpp std_msgs)

add_executable(simple_subscriber src/subscriber.cpp)
ament_target_dependencies(simple_subscriber rclcpp std_msgs)

add_executable(simple_parameter src/simple_parameter.cpp)
ament_target_dependencies(simple_parameter rclcpp rcl_interfaces)

add_executable(turtlesim_kinematics src/turtlesim_kinematics.cpp)
ament_target_dependencies(turtlesim_kinematics rclcpp turtlesim)


install(TARGETS
  simple_publisher
  simple_subscriber
  simple_parameter
  turtlesim_kinematics
  DESTINATION lib/${PROJECT_NAME})

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  set(ament_cmake_copyright_FOUND TRUE)
  set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()

# Install header files
install(DIRECTORY include/
  DESTINATION include/${PROJECT_NAME})

ament_package()
