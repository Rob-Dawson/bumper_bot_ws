cmake_minimum_required(VERSION 3.8)
project(bumperbot_description)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(gazebo REQUIRED)
find_package(gazebo_ros REQUIRED)
find_package(rclcpp REQUIRED)



if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  set(ament_cmake_copyright_FOUND TRUE)
  set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()


# include_directories(${GAZEBO_INCLUDE_DIRS})

# link_directories(${GAZEBO_LIBRARY_DIRS})

add_library(hello_world SHARED plugin/hello_world.cc)

target_include_directories(hello_world PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include>)

ament_target_dependencies(hello_world
  "gazebo_ros"
  "rclcpp"
  )


  install(TARGETS
  hello_world
  DESTINATION share/${PROJECT_NAME})



# target_link_libraries(hello_world ${GAZEBO_LIBRARIES})
# install(TARGETS hello_world DESTINATION lib)


  
install (
  DIRECTORY launch meshes urdf rviz2 worlds
  DESTINATION share/${PROJECT_NAME}
)


ament_package()
