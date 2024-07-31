#include "subscriber.h"
using std::placeholders::_1;

SimpleSubscriber::SimpleSubscriber() : Node("simple_subscriber")
{
    sub_ = create_subscription<std_msgs::msg::String>("talker", 10, std::bind(&SimpleSubscriber::msgCallback, this, _1));
}

void SimpleSubscriber::msgCallback(const std_msgs::msg::String &msg) const
{
    RCLCPP_INFO_STREAM(get_logger(), "I Heard " << msg.data.c_str());
}

int main(int argc, char *argv[])
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<SimpleSubscriber>();
    rclcpp::spin(node);
    rclcpp::shutdown();
}