#include "turtlesim_kinematics.hpp"
using std::placeholders::_1;


TurtleSimKinematics::TurtleSimKinematics(const std::string &name) : Node(name)
{
    subTurtle1 = create_subscription<turtlesim::msg::Pose>("/turtle1/pose", 10, std::bind(&TurtleSimKinematics::turtle1PoseCallback, this, _1));
    subTurtle2 = create_subscription<turtlesim::msg::Pose>("/turtle2/pose", 10, std::bind(&TurtleSimKinematics::turtle2PoseCallback, this, _1));
}

void TurtleSimKinematics::turtle1PoseCallback(const turtlesim::msg::Pose &pose1)
{
    lastTurtle1Pose = pose1;
}

void TurtleSimKinematics::turtle2PoseCallback(const turtlesim::msg::Pose &pose2)
{
    lastTurtle2Pose = pose2;
    float Tx = lastTurtle2Pose.x - lastTurtle1Pose.x;
    float Ty = lastTurtle2Pose.y - lastTurtle1Pose.y;
    

    float thetaRad = lastTurtle2Pose.theta - lastTurtle1Pose.theta;
    float thettaDeg = 180 * thetaRad / 3.141;
    
    RCLCPP_INFO_STREAM(get_logger(), "\nTranslation Vector turtle1 and turtle 2 \n" << 
    "Tx: " << Tx << 
    "\n Ty" << Ty << 
    "\n" << "Rotation Matrix turtle 1 -> turtle 2" <<
    "theta(rad): " << thetaRad << "\n" <<
    "theta(deg): " << thettaDeg << "\n" <<
    "|R11        R12|:   |" << std::cos(thetaRad) << "\t" << -std::sin(thetaRad) << "|\n" <<
    "|R21       R22|    |" <<  std::sin(thetaRad) << "\t" << -std::cos(thetaRad) <<"|\n");


}

int main(int argc, char *argv[])
{
    rclcpp::init(argc, argv);
    auto turtle = std::make_shared<TurtleSimKinematics>("turtlesim_kinematics");
    rclcpp::spin(turtle);
    rclcpp::shutdown();
}