#include <rclcpp/rclcpp.hpp>
#include <turtlesim/msg/pose.hpp>
class TurtleSimKinematics : public rclcpp::Node
{
public:
    TurtleSimKinematics(const std::string &name);

private:
    // rclcpp::Publisher<geometry_msgs::msg::Twist>::SharedPtr pub;

    void turtle1PoseCallback(const turtlesim::msg::Pose &pose1);
    void turtle2PoseCallback(const turtlesim::msg::Pose &pose2);
    rclcpp::Subscription<turtlesim::msg::Pose>::SharedPtr subTurtle1;
    rclcpp::Subscription<turtlesim::msg::Pose>::SharedPtr subTurtle2;

    turtlesim::msg::Pose lastTurtle1Pose;
    turtlesim::msg::Pose lastTurtle2Pose;
};

