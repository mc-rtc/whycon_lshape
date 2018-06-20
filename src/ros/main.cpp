#include <ros/ros.h>
#include "whycon_lshape_ros.h"

int main(int argc, char**argv)
{
  ros::init(argc, argv, "whycon_lshape");
  ros::NodeHandle n("~");

  whycon_lshape::WhyConLShapeROS node(n);
  ros::spin();
}
