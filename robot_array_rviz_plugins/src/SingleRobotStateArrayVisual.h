#pragma once

#include <RBDyn/MultiBodyConfig.h>

#include <rviz/display.h>
#include <rviz/robot/robot.h>

namespace RobotArrayRvizPlugins
{
class SingleRobotStateArrayVisual
{
public:
  SingleRobotStateArrayVisual();

  ~SingleRobotStateArrayVisual();

  void reset();

  void update(const rbd::MultiBody & mb, const std::vector<rbd::MultiBodyConfig> & mbc_list);

  void allocateRobotModel(int num,
                          Ogre::SceneNode * root_node,
                          rviz::DisplayContext * context,
                          rviz::Property * parent_property);

  void loadRobotModel(const urdf::ModelInterface & urdf_model);

  void setVisible(int num);

  void setColor(int idx, bool original, const Ogre::ColourValue & color);

  std::vector<std::shared_ptr<rviz::Robot>> robot_list_;

protected:
  std::vector<rviz::BoolProperty *> robot_property_list_;
};
} // namespace RobotArrayRvizPlugins
