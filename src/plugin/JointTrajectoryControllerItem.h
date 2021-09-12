#ifndef CNOID_JOINT_TRAJECTORY_CONTROLLER_ITEM_H
#define CNOID_JOINT_TRAJECTORY_CONTROLLER_ITEM_H

#include <cnoid/Archive>
#include <cnoid/Body>
#include <cnoid/BodyItem>
#include <cnoid/ControllerItem>
#include <cnoid/ItemManager>
#include <cnoid/Link>
#include <cnoid/MessageView>

#include <ros/ros.h>
#include <trajectory_msgs/JointTrajectory.h>

#include "exportdecl.h"

namespace cnoid
{
class CNOID_EXPORT JointTrajectoryControllerItem : public ControllerItem
{
public:
  static void initializeClass(ExtensionManager* ext);

  JointTrajectoryControllerItem();
  JointTrajectoryControllerItem(const JointTrajectoryControllerItem& org);
  virtual ~JointTrajectoryControllerItem();

  virtual bool initialize(ControllerIO* io) override;
  virtual bool start() override;

  virtual double timeStep() const override
  {
    return timeStep_;
  }
  virtual void input() override;
  virtual bool control() override;
  virtual void output() override;
  virtual void stop() override;

  const BodyPtr& body() const
  {
    return simulationBody_;
  }
  double controlTime() const
  {
    return controlTime_;
  }

protected:
  virtual Item* doDuplicate() const override;
  virtual bool store(Archive& archive) override;
  virtual bool restore(const Archive& archive) override;
  void doPutProperties(PutPropertyFunction& putProperty) override;

  BodyPtr simulationBody_;
  double timeStep_;

  ControllerIO* io;
  const Target* contrllerTarget_;
  double controlTime_;

  boost::shared_ptr<ros::NodeHandle> ros_node_;
  boost::shared_ptr<ros::AsyncSpinner> async_ros_spin_;
};

typedef ref_ptr<JointTrajectoryControllerItem> JointTrajectoryControllerItemPtr;

}  // namespace cnoid

#endif
