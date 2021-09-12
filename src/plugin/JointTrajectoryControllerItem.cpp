#include "JointTrajectoryControllerItem.h"
#include "gettext.h"
#include <fmt/format.h>

using namespace cnoid;
using fmt::format;

void JointTrajectoryControllerItem::initializeClass(ExtensionManager* ext)
{
  ext->itemManager().registerClass<JointTrajectoryControllerItem>(N_("JointTrajectoryControllerItem"));
  ext->itemManager().addCreationPanel<JointTrajectoryControllerItem>();
}

JointTrajectoryControllerItem::JointTrajectoryControllerItem()
{
  io = nullptr;
}

JointTrajectoryControllerItem::JointTrajectoryControllerItem(const JointTrajectoryControllerItem& org)
: ControllerItem(org)
{
  io = nullptr;
}

JointTrajectoryControllerItem::~JointTrajectoryControllerItem()
{
  stop();
}

Item* JointTrajectoryControllerItem::doDuplicate() const
{
  return new JointTrajectoryControllerItem(*this);
}

void JointTrajectoryControllerItem::doPutProperties(PutPropertyFunction& purtProperty)
{
  return;
}

bool JointTrajectoryControllerItem::store(Archive& archive)
{
  return true;
}

bool JointTrajectoryControllerItem::restore(const Archive& archive)
{
  return true;
}

bool JointTrajectoryControllerItem::initialize(ControllerIO* io)
{
  if (!io->body()) {
    MessageView::instance()->putln(
      format(
        _("JointTrajectoryControllerItem \"{0}\" is invalid because it is not assigned to a body."), displayName()),
      MessageView::WARNING);
    return false;
  }

  this->io = io;
  simulationBody_ = io->body();
  timeStep_ = io->worldTimeStep();
  controlTime_ = io->currentTime();

  return true;
}

bool JointTrajectoryControllerItem::start()
{
  return true;
}

bool JointTrajectoryControllerItem::control()
{
  return true;
}

void JointTrajectoryControllerItem::input()
{
  return;
}

void JointTrajectoryControllerItem::output()
{
  return;
}

void JointTrajectoryControllerItem::stop()
{
  return;
}
