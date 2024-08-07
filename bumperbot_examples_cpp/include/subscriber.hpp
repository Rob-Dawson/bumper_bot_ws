#ifndef SIMPLE_SUBSCRIBER_H
#define SIMPLE_SUBSCRIBER_H

#include <rclcpp/rclcpp.hpp>
#include <std_msgs/msg/string.hpp>
#include <rclcpp/subscription.hpp>

class SimpleSubscriber : public rclcpp::Node
{
public:
    SimpleSubscriber();

private:
    void msgCallback(const std_msgs::msg::String &msg)const;
    rclcpp::Subscription<std_msgs::msg::String>::SharedPtr sub_;
};


#endif