import os
import os.path
from launch import LaunchDescription
from launch_ros.substitutions import FindPackageShare
from launch_ros.actions import Node
import xacro
from launch.actions import DeclareLaunchArgument
from launch_ros.parameter_descriptions import ParameterValue
from launch.substitutions import Command, LaunchConfiguration
from ament_index_python import get_package_share_directory
def generate_launch_description():


    pkg_path = get_package_share_directory("bumperbot_description")

    # xacro_path = os.path.join(pkg_path, "urdf", "bumperbot.urdf.xacro")
    rviz2_config = os.path.join(pkg_path, "rviz2", "display.rviz")
    #This declares an argument called model with the default value being the path to the xacro model
    model_arg = DeclareLaunchArgument(
        name="model",
        default_value=os.path.join(pkg_path, "urdf", "bumperbot.urdf.xacro"),
        description="Use Simulation (Gazebo) clock if true",
    )

    #Command takes a list of "commands" here, the command is xacro
    #The LaunchConfiguration reads the value of the model argument above
    #This is the same as doing "xacro bumperbot.urdf.xacro" in the terminal
    robot_description = ParameterValue(Command(["xacro ", LaunchConfiguration("model")]), value_type=str)


    robot_state_publisher = Node(
        package="robot_state_publisher",
        executable="robot_state_publisher",
        parameters=[{"robot_description": robot_description}],
    )

    joint_state_publisher_gui = Node(
        package="joint_state_publisher_gui",
        executable="joint_state_publisher_gui",
    )

    rviz2_node = Node(
        package="rviz2",
        executable="rviz2",
        name='rviz2',
        output="screen",
        arguments=["-d", rviz2_config]
    )

    ld = LaunchDescription()
    ld.add_action(model_arg)
    ld.add_action(robot_state_publisher)
    ld.add_action(joint_state_publisher_gui)
    ld.add_action(rviz2_node)

    return ld

