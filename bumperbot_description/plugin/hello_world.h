#ifndef hello_world
#define hello_world

#include <gazebo/common/Plugin.hh>
#include <gazebo/gazebo.hh>
#include <gazebo/common/common.hh>
#include <rclcpp/rclcpp.hpp>

namespace gazebo
{
    class WorldPluginTutorial : public WorldPlugin
    {
    public:
        WorldPluginTutorial();

        void Load(physics::WorldPtr _world, sdf::ElementPtr _sdf);

    private:
        rclcpp::Node::SharedPtr node_;
    };

    GZ_REGISTER_WORLD_PLUGIN(WorldPluginTutorial)
}

#endif // WORLD_PLUGIN_TUTORIAL_H
