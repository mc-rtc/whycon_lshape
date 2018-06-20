import rospy

from geometry_msgs.msg import PoseArray
from augmented_whycon.msg import AugmentedWhyConMsg

 def __init__(self, rm, dt):
    rospy.init_node('rtc_demo_breaker')
    rospy.Subscriber("/augmented_whycon/augmented_whycon", AugmentedWhyConMsg,
          self.callbackAugmentedWhyconMarker)

def callbackAugmentedWhyconMarker(self, data):
    self.data = data
    self.ms_since_last_whycon_callback = 0

    for i in data.nrDetectedLshapes
        # check if tool is detected
        if data.LShapesIdxs[i] == 1
            pos = data.LShapesPos[i]
            pos = Vector3d(pos.x, pos.y, pos.z)
            quat = data.LShapesOri[i]
            quat = Quaterniond(quat.w, quat.x, quat.y, quat.z)
            self.REAL_tool_marker(pos, quat)
