

// #ifndef SIMPLE_PUBLISHER_H
// #define SIMPLE_PUBLISHER_H

// #include <rclcpp/rclcpp.hpp>
// #include <std_msgs/msg/string.hpp>
// #include <chrono>

// using namespace std::chrono_literals;

// class SimplePublisher : public rclcpp::Node
// {
// public:
//     SimplePublisher();

// private:
//     unsigned int counter;
//     rclcpp::Publisher<std_msgs::msg::String>::SharedPtr pub_;
//     rclcpp::TimerBase::SharedPtr timer;
//     void timerCallback();
// };


// #endif


// #ifndef SIMPLE_PUBLISHER_H
// #define SIMPLE_PUBLISHER_H

// #include <rclcpp/rclcpp.hpp>
// #include <std_msgs/msg/string.hpp>
// #include <chrono>

// using namespace std::chrono_literals;

// class SimplePublisher : public rclcpp::Node
// {

// public:
//     SimplePublisher();
// private:
//     int counter;
//     rclcpp::Publisher<std_msgs::msg::String>::SharedPtr pub_;
//     rclcpp::TimerBase::SharedPtr timer;
//     void timerCallback();
// };

// #endif

#ifndef SIMPLE_PUBLISHER_H
#define SIMPLE_PUBLISHER_H

#include <rclcpp/rclcpp.hpp>
#include <std_msgs/msg/string.hpp>
#include <chrono>

using namespace std::chrono_literals;

class SimplePublisher : public rclcpp::Node
{
public:
    SimplePublisher();
private:
    int m_counter;
    rclcpp::Publisher<std_msgs::msg::String>::SharedPtr m_pub;
    rclcpp::TimerBase::SharedPtr m_timer;
    void callback();
};

#endif




























