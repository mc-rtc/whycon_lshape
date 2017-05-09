; Auto-generated. Do not edit!


(cl:in-package augmented_whycon-msg)


;//! \htmlinclude AugmentedWhyConMsg.msg.html

(cl:defclass <AugmentedWhyConMsg> (roslisp-msg-protocol:ros-message)
  ((header
    :reader header
    :initarg :header
    :type std_msgs-msg:Header
    :initform (cl:make-instance 'std_msgs-msg:Header))
   (poses
    :reader poses
    :initarg :poses
    :type (cl:vector geometry_msgs-msg:Pose)
   :initform (cl:make-array 0 :element-type 'geometry_msgs-msg:Pose :initial-element (cl:make-instance 'geometry_msgs-msg:Pose)))
   (nrDetectedLShapes
    :reader nrDetectedLShapes
    :initarg :nrDetectedLShapes
    :type (cl:vector geometry_msgs-msg:Vector3)
   :initform (cl:make-array 0 :element-type 'geometry_msgs-msg:Vector3 :initial-element (cl:make-instance 'geometry_msgs-msg:Vector3)))
   (idx
    :reader idx
    :initarg :idx
    :type (cl:vector geometry_msgs-msg:Vector3)
   :initform (cl:make-array 0 :element-type 'geometry_msgs-msg:Vector3 :initial-element (cl:make-instance 'geometry_msgs-msg:Vector3)))
   (LShapesIdxs
    :reader LShapesIdxs
    :initarg :LShapesIdxs
    :type (cl:vector geometry_msgs-msg:Vector3)
   :initform (cl:make-array 0 :element-type 'geometry_msgs-msg:Vector3 :initial-element (cl:make-instance 'geometry_msgs-msg:Vector3)))
   (LShapesOri
    :reader LShapesOri
    :initarg :LShapesOri
    :type (cl:vector geometry_msgs-msg:Quaternion)
   :initform (cl:make-array 0 :element-type 'geometry_msgs-msg:Quaternion :initial-element (cl:make-instance 'geometry_msgs-msg:Quaternion))))
)

(cl:defclass AugmentedWhyConMsg (<AugmentedWhyConMsg>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <AugmentedWhyConMsg>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'AugmentedWhyConMsg)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name augmented_whycon-msg:<AugmentedWhyConMsg> is deprecated: use augmented_whycon-msg:AugmentedWhyConMsg instead.")))

(cl:ensure-generic-function 'header-val :lambda-list '(m))
(cl:defmethod header-val ((m <AugmentedWhyConMsg>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader augmented_whycon-msg:header-val is deprecated.  Use augmented_whycon-msg:header instead.")
  (header m))

(cl:ensure-generic-function 'poses-val :lambda-list '(m))
(cl:defmethod poses-val ((m <AugmentedWhyConMsg>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader augmented_whycon-msg:poses-val is deprecated.  Use augmented_whycon-msg:poses instead.")
  (poses m))

(cl:ensure-generic-function 'nrDetectedLShapes-val :lambda-list '(m))
(cl:defmethod nrDetectedLShapes-val ((m <AugmentedWhyConMsg>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader augmented_whycon-msg:nrDetectedLShapes-val is deprecated.  Use augmented_whycon-msg:nrDetectedLShapes instead.")
  (nrDetectedLShapes m))

(cl:ensure-generic-function 'idx-val :lambda-list '(m))
(cl:defmethod idx-val ((m <AugmentedWhyConMsg>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader augmented_whycon-msg:idx-val is deprecated.  Use augmented_whycon-msg:idx instead.")
  (idx m))

(cl:ensure-generic-function 'LShapesIdxs-val :lambda-list '(m))
(cl:defmethod LShapesIdxs-val ((m <AugmentedWhyConMsg>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader augmented_whycon-msg:LShapesIdxs-val is deprecated.  Use augmented_whycon-msg:LShapesIdxs instead.")
  (LShapesIdxs m))

(cl:ensure-generic-function 'LShapesOri-val :lambda-list '(m))
(cl:defmethod LShapesOri-val ((m <AugmentedWhyConMsg>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader augmented_whycon-msg:LShapesOri-val is deprecated.  Use augmented_whycon-msg:LShapesOri instead.")
  (LShapesOri m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <AugmentedWhyConMsg>) ostream)
  "Serializes a message object of type '<AugmentedWhyConMsg>"
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'header) ostream)
  (cl:let ((__ros_arr_len (cl:length (cl:slot-value msg 'poses))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_arr_len) ostream))
  (cl:map cl:nil #'(cl:lambda (ele) (roslisp-msg-protocol:serialize ele ostream))
   (cl:slot-value msg 'poses))
  (cl:let ((__ros_arr_len (cl:length (cl:slot-value msg 'nrDetectedLShapes))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_arr_len) ostream))
  (cl:map cl:nil #'(cl:lambda (ele) (roslisp-msg-protocol:serialize ele ostream))
   (cl:slot-value msg 'nrDetectedLShapes))
  (cl:let ((__ros_arr_len (cl:length (cl:slot-value msg 'idx))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_arr_len) ostream))
  (cl:map cl:nil #'(cl:lambda (ele) (roslisp-msg-protocol:serialize ele ostream))
   (cl:slot-value msg 'idx))
  (cl:let ((__ros_arr_len (cl:length (cl:slot-value msg 'LShapesIdxs))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_arr_len) ostream))
  (cl:map cl:nil #'(cl:lambda (ele) (roslisp-msg-protocol:serialize ele ostream))
   (cl:slot-value msg 'LShapesIdxs))
  (cl:let ((__ros_arr_len (cl:length (cl:slot-value msg 'LShapesOri))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_arr_len) ostream))
  (cl:map cl:nil #'(cl:lambda (ele) (roslisp-msg-protocol:serialize ele ostream))
   (cl:slot-value msg 'LShapesOri))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <AugmentedWhyConMsg>) istream)
  "Deserializes a message object of type '<AugmentedWhyConMsg>"
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'header) istream)
  (cl:let ((__ros_arr_len 0))
    (cl:setf (cl:ldb (cl:byte 8 0) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) __ros_arr_len) (cl:read-byte istream))
  (cl:setf (cl:slot-value msg 'poses) (cl:make-array __ros_arr_len))
  (cl:let ((vals (cl:slot-value msg 'poses)))
    (cl:dotimes (i __ros_arr_len)
    (cl:setf (cl:aref vals i) (cl:make-instance 'geometry_msgs-msg:Pose))
  (roslisp-msg-protocol:deserialize (cl:aref vals i) istream))))
  (cl:let ((__ros_arr_len 0))
    (cl:setf (cl:ldb (cl:byte 8 0) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) __ros_arr_len) (cl:read-byte istream))
  (cl:setf (cl:slot-value msg 'nrDetectedLShapes) (cl:make-array __ros_arr_len))
  (cl:let ((vals (cl:slot-value msg 'nrDetectedLShapes)))
    (cl:dotimes (i __ros_arr_len)
    (cl:setf (cl:aref vals i) (cl:make-instance 'geometry_msgs-msg:Vector3))
  (roslisp-msg-protocol:deserialize (cl:aref vals i) istream))))
  (cl:let ((__ros_arr_len 0))
    (cl:setf (cl:ldb (cl:byte 8 0) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) __ros_arr_len) (cl:read-byte istream))
  (cl:setf (cl:slot-value msg 'idx) (cl:make-array __ros_arr_len))
  (cl:let ((vals (cl:slot-value msg 'idx)))
    (cl:dotimes (i __ros_arr_len)
    (cl:setf (cl:aref vals i) (cl:make-instance 'geometry_msgs-msg:Vector3))
  (roslisp-msg-protocol:deserialize (cl:aref vals i) istream))))
  (cl:let ((__ros_arr_len 0))
    (cl:setf (cl:ldb (cl:byte 8 0) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) __ros_arr_len) (cl:read-byte istream))
  (cl:setf (cl:slot-value msg 'LShapesIdxs) (cl:make-array __ros_arr_len))
  (cl:let ((vals (cl:slot-value msg 'LShapesIdxs)))
    (cl:dotimes (i __ros_arr_len)
    (cl:setf (cl:aref vals i) (cl:make-instance 'geometry_msgs-msg:Vector3))
  (roslisp-msg-protocol:deserialize (cl:aref vals i) istream))))
  (cl:let ((__ros_arr_len 0))
    (cl:setf (cl:ldb (cl:byte 8 0) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) __ros_arr_len) (cl:read-byte istream))
  (cl:setf (cl:slot-value msg 'LShapesOri) (cl:make-array __ros_arr_len))
  (cl:let ((vals (cl:slot-value msg 'LShapesOri)))
    (cl:dotimes (i __ros_arr_len)
    (cl:setf (cl:aref vals i) (cl:make-instance 'geometry_msgs-msg:Quaternion))
  (roslisp-msg-protocol:deserialize (cl:aref vals i) istream))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<AugmentedWhyConMsg>)))
  "Returns string type for a message object of type '<AugmentedWhyConMsg>"
  "augmented_whycon/AugmentedWhyConMsg")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'AugmentedWhyConMsg)))
  "Returns string type for a message object of type 'AugmentedWhyConMsg"
  "augmented_whycon/AugmentedWhyConMsg")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<AugmentedWhyConMsg>)))
  "Returns md5sum for a message object of type '<AugmentedWhyConMsg>"
  "4b77e673bc19c526df867e458fa38e03")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'AugmentedWhyConMsg)))
  "Returns md5sum for a message object of type 'AugmentedWhyConMsg"
  "4b77e673bc19c526df867e458fa38e03")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<AugmentedWhyConMsg>)))
  "Returns full string definition for message of type '<AugmentedWhyConMsg>"
  (cl:format cl:nil "Header header~%geometry_msgs/Pose[] poses~%geometry_msgs/Vector3[] nrDetectedLShapes~%geometry_msgs/Vector3[] idx~%geometry_msgs/Vector3[] LShapesIdxs~%geometry_msgs/Quaternion[] LShapesOri~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%# 0: no frame~%# 1: global frame~%string frame_id~%~%================================================================================~%MSG: geometry_msgs/Pose~%# A representation of pose in free space, composed of postion and orientation. ~%Point position~%Quaternion orientation~%~%================================================================================~%MSG: geometry_msgs/Point~%# This contains the position of a point in free space~%float64 x~%float64 y~%float64 z~%~%================================================================================~%MSG: geometry_msgs/Quaternion~%# This represents an orientation in free space in quaternion form.~%~%float64 x~%float64 y~%float64 z~%float64 w~%~%================================================================================~%MSG: geometry_msgs/Vector3~%# This represents a vector in free space. ~%# It is only meant to represent a direction. Therefore, it does not~%# make sense to apply a translation to it (e.g., when applying a ~%# generic rigid transformation to a Vector3, tf2 will only apply the~%# rotation). If you want your data to be translatable too, use the~%# geometry_msgs/Point message instead.~%~%float64 x~%float64 y~%float64 z~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'AugmentedWhyConMsg)))
  "Returns full string definition for message of type 'AugmentedWhyConMsg"
  (cl:format cl:nil "Header header~%geometry_msgs/Pose[] poses~%geometry_msgs/Vector3[] nrDetectedLShapes~%geometry_msgs/Vector3[] idx~%geometry_msgs/Vector3[] LShapesIdxs~%geometry_msgs/Quaternion[] LShapesOri~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%# 0: no frame~%# 1: global frame~%string frame_id~%~%================================================================================~%MSG: geometry_msgs/Pose~%# A representation of pose in free space, composed of postion and orientation. ~%Point position~%Quaternion orientation~%~%================================================================================~%MSG: geometry_msgs/Point~%# This contains the position of a point in free space~%float64 x~%float64 y~%float64 z~%~%================================================================================~%MSG: geometry_msgs/Quaternion~%# This represents an orientation in free space in quaternion form.~%~%float64 x~%float64 y~%float64 z~%float64 w~%~%================================================================================~%MSG: geometry_msgs/Vector3~%# This represents a vector in free space. ~%# It is only meant to represent a direction. Therefore, it does not~%# make sense to apply a translation to it (e.g., when applying a ~%# generic rigid transformation to a Vector3, tf2 will only apply the~%# rotation). If you want your data to be translatable too, use the~%# geometry_msgs/Point message instead.~%~%float64 x~%float64 y~%float64 z~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <AugmentedWhyConMsg>))
  (cl:+ 0
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'header))
     4 (cl:reduce #'cl:+ (cl:slot-value msg 'poses) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ (roslisp-msg-protocol:serialization-length ele))))
     4 (cl:reduce #'cl:+ (cl:slot-value msg 'nrDetectedLShapes) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ (roslisp-msg-protocol:serialization-length ele))))
     4 (cl:reduce #'cl:+ (cl:slot-value msg 'idx) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ (roslisp-msg-protocol:serialization-length ele))))
     4 (cl:reduce #'cl:+ (cl:slot-value msg 'LShapesIdxs) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ (roslisp-msg-protocol:serialization-length ele))))
     4 (cl:reduce #'cl:+ (cl:slot-value msg 'LShapesOri) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ (roslisp-msg-protocol:serialization-length ele))))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <AugmentedWhyConMsg>))
  "Converts a ROS message object to a list"
  (cl:list 'AugmentedWhyConMsg
    (cl:cons ':header (header msg))
    (cl:cons ':poses (poses msg))
    (cl:cons ':nrDetectedLShapes (nrDetectedLShapes msg))
    (cl:cons ':idx (idx msg))
    (cl:cons ':LShapesIdxs (LShapesIdxs msg))
    (cl:cons ':LShapesOri (LShapesOri msg))
))
