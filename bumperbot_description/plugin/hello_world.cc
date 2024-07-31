#include "hello_world.h"
#include <gazebo/physics/World.hh> // Include the header for World class
#include <gazebo/transport/transport.hh> // Include for transport


namespace gazebo
{
    WorldPluginTutorial::WorldPluginTutorial() 
        : WorldPlugin(), node_(rclcpp::Node::make_shared("gazebo_world_plugin_tutorial"))
    {
        printf("Hello World");

    }

    void WorldPluginTutorial::Load(physics::WorldPtr _world, sdf::ElementPtr _sdf)
    {
        //_world pointer can access the world name using Name() fn
        std::cout << "World Name: " << _world->Name() << std::endl;
        
        // //set up a node to publish using Gazebo publisher
        // transport::NodePtr node(new transport::Node());
        // node->Init(_world->Name());
        
        // //set publisher
        // transport::PublisherPtr publisher = node->Advertise<msgs::Factory>("~/factory");

        // //Creating a msg object. This is used to communicate between the gazebo subscribers and publishers
        // msgs::Factory msg;
        // msg.set_sdf("model://table");
        
        // msgs::Set(msg.mutable_pose(), ignition::math::Pose3d(1.0,1.0,0.0,1.0,1.0,0.0));
        // publisher->Publish(msg);
        
        // Initialize ROS 2
        if (!rclcpp::ok())
        {
            RCLCPP_FATAL(rclcpp::get_logger("rclcpp"), "A ROS node for Gazebo has not been initialized, unable to load plugin.");
            return;
        }

        RCLCPP_INFO(node_->get_logger(), "Hello EVERYONE FROM ROS2!");
    }
}
