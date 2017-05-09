#include <ros/ros.h>
#include "augmented_whycon_ros.h"

int main(int argc, char**argv)
{
  ros::init(argc, argv, "augmented_whycon");
  ros::NodeHandle n("~");

  augmented_whycon::AugmentedWhyConROS node(n);
  ros::spin();
}
