# import os
# from os import pathsep
# from launch import LaunchDescription
# from launch.substitutions import LaunchConfiguration, Command
# from launch_ros.substitutions import FindPackageShare
# from launch.actions import DeclareLaunchArgument, LogInfo, SetEnvironmentVariable
# from launch.actions import IncludeLaunchDescription
# from launch_ros.actions import Node
# from launch.launch_description_sources import PythonLaunchDescriptionSource
# from ament_index_python import get_package_prefix, get_package_share_directory
# from launch_ros.parameter_descriptions import ParameterValue
# def generate_launch_description():

#     bumperbot_description = get_package_share_directory("bumperbot_description")
#     bumperbot_description_prefix = get_package_prefix("bumperbot_description")

#     print(bumperbot_description)
#     model_path = os.path.join(bumperbot_description, "urdf")
#     print(model_path)
#     model_path += pathsep + os.path.join(bumperbot_description_prefix, "share")
#     print(model_path)

#     GAZEBO_PATH = FindPackageShare("gazebo_ros").find("gazebo_ros")

#     env_variable = SetEnvironmentVariable("GAZEBO_MODEL_PATH", model_path)



#     model_arg = DeclareLaunchArgument(name="model", default_value=os.path.join
#                                       (bumperbot_description, "urdf", "bumperbot_gazebo.urdf.xacro"),
#                                       description="Absolute path to the robot urdf file")
    
#     robot_description = ParameterValue(Command(["xacro", LaunchConfiguration("model")]), value_type=str)




#     robot_state_publisher_node = Node(package="robot_state_publisher",
#                                       executable="robot_state_publisher",
#                                       parameters=[{"robot_description" : robot_description}]

#     )

#     gazebo_server = IncludeLaunchDescription(
#         PythonLaunchDescriptionSource([os.path.join(
#             GAZEBO_PATH, "launch", "gzserver.launch.py" 
#         )]),
#         # launch_arguments={
#         #     'verbose':"true",
#         #     'world': GAZEBO_WORLD}.items()
#     )

#     gazebo_client = IncludeLaunchDescription(
#         PythonLaunchDescriptionSource([os.path.join(
#             GAZEBO_PATH, "launch", "gzclient.launch.py" 
#         )]),
#         # launch_arguments={
#         #     'verbose':"true",
#         #     'world': GAZEBO_WORLD}.items()
#     )


#     spawner = Node( package="gazebo_ros", 
#                     executable="spawn_entity.py", 
#                     arguments=["-entity", "bumperbot", 
#                               "-topic", "robot_description"],
#                     output="screen")
    

#     ld = LaunchDescription()
#     ld.add_action(env_variable)
#     ld.add_action(model_arg)
#     ld.add_action(robot_state_publisher_node)
#     ld.add_action(gazebo_server)
#     ld.add_action(gazebo_client)
#     ld.add_action(spawner)

#     return ld
#     # try:
#     #     PKG_PATH = FindPackageShare("bumperbot_description").find("bumperbot_description")
#     # except FileNotFoundError:
#     #     LogInfo("Cannot find package")
#     # try:
#     #     GAZEBO_WORLD = os.path.join(PKG_PATH, "worlds", "empty.world")
#     # except:
#     #     print("Cannot find world")

#     # try:
#     #     MODEL_PATH = os.path.join(PKG_PATH, "urdf", "bumperbot_gazebo.urdf.xacro")
#     # except:
#     #     print("Cannot find model")
#     # GAZEBO_PATH = FindPackageShare("gazebo_ros").find("gazebo_ros")

#     # gazebo = IncludeLaunchDescription(
#     #     PythonLaunchDescriptionSource([os.path.join(
#     #         GAZEBO_PATH, "launch", "gazebo.launch.py" 
#     #     )]),
#     #     launch_arguments={
#     #         'verbose':"true",
#     #         'world': GAZEBO_WORLD}.items()
#     # )
#     # ld = LaunchDescription()
#     # ld.add_action(gazebo)
#     # return ld




import os
import os.path
from launch import LaunchDescription
from launch.actions import IncludeLaunchDescription
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch_ros.actions import Node
from launch_ros.substitutions import FindPackageShare
from launch.substitutions import LaunchConfiguration
from launch.actions import DeclareLaunchArgument, LogInfo

def generate_launch_description():


#region Path to Files
    try:
        PKG_PATH = FindPackageShare("bumperbot_description").find("bumperbot_description")
    except FileNotFoundError:
        LogInfo("Cannot find package")


    ##  Path to XACRO
    try:
        XACRO_PATH = os.path.join(PKG_PATH, "urdf", ".urdf.xacro")
    except FileNotFoundError:
        LogInfo("Cannot find robot file")

    ## Path to Gazebo Classic
    GAZEBO_PATH = FindPackageShare("gazebo_ros").find("gazebo_ros")

    ## Path to Gazebo World
    try:
        GAZEBO_WORLD = os.path.join(PKG_PATH, "worlds", "empty.world")
    except:
        print("Cannot find world")

#endregion 

#region Include Launch Descriptions

    rsp = IncludeLaunchDescription(
        PythonLaunchDescriptionSource([os.path.join(
            PKG_PATH, "launch", "rsp.launch.py"
        )]),
        launch_arguments={'use_sim_time':'true'}.items()
    )


    gazebo = IncludeLaunchDescription(
        PythonLaunchDescriptionSource([os.path.join(
            GAZEBO_PATH, "launch", "gazebo.launch.py" 
        )]),
        launch_arguments={
            'verbose':"true",
            'world': GAZEBO_WORLD}.items()
    )


#endregion

#region Nodes

    spawn_entity = Node(
        package="gazebo_ros",
        executable='spawn_entity.py',
        arguments=['-topic', "robot_description", "-entity", "bumperbot"],
        output="screen"
    )
#endregion
    # joint_state_broadcaster_spawner = Node(
    #     package="controller_manager",
    #     executable="spawner",
    #     arguments=["joint_state_broadcaster", "--controller-manager", "/controller_manager"],
    # )

    # robot_controller_spawner = Node(
    #     package="controller_manager",
    #     executable="spawner",
    #     arguments=["joint_trajectory_controller", "--controller-manager", "/controller_manager"],
    # )

#region Add Launch Descriptions
    ld = LaunchDescription()
    ld.add_action(rsp)
    ld.add_action(gazebo)
    ld.add_action(spawn_entity)
    # ld.add_action(joint_state_broadcaster_spawner)
    # ld.add_action(robot_controller_spawner)

#endregion

    return ld