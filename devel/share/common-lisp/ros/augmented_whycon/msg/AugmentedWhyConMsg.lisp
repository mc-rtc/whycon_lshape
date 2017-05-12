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
    :type geometry_msgs-msg:Point
    :initform (cl:make-instance 'geometry_msgs-msg:Point))
   (idx
    :reader idx
    :initarg :idx
    :type (cl:vector geometry_msgs-msg:Point)
   :initform (cl:make-array 0 :element-type 'geometry_msgs-msg:Point :initial-element (cl:make-instance 'geometry_msgs-msg:Point)))
   (LShapesIdxs
    :reader LShapesIdxs
    :initarg :LShapesIdxs
    :type geometry_msgs-msg:Point
    :initform (cl:make-instance 'geometry_msgs-msg:Point))
   (LShapesPos
    :reader LShapesPos
    :initarg :LShapesPos
    :type (cl:vector geometry_msgs-msg:Point)
   :initform (cl:make-array 0 :element-type 'geometry_msgs-msg:Point :initial-element (cl:make-instance 'geometry_msgs-msg:Point)))
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

(cl:ensure-generic-function 'LShapesPos-val :lambda-list '(m))
(cl:defmethod LShapesPos-val ((m <AugmentedWhyConMsg>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader augmented_whycon-msg:LShapesPos-val is deprecated.  Use augmented_whycon-msg:LShapesPos instead.")
  (LShapesPos m))

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
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'nrDetectedLShapes) ostream)
  (cl:let ((__ros_arr_len (cl:length (cl:slot-value msg 'idx))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_arr_len) ostream))
  (cl:map cl:nil #'(cl:lambda (ele) (roslisp-msg-protocol:serialize ele ostream))
   (cl:slot-value msg 'idx))
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'LShapesIdxs) ostream)
  (cl:let ((__ros_arr_len (cl:length (cl:slot-value msg 'LShapesPos))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_arr_len) ostream))
  (cl:map cl:nil #'(cl:lambda (ele) (roslisp-msg-protocol:serialize ele ostream))
   (cl:slot-value msg 'LShapesPos))
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
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'nrDetectedLShapes) istream)
  (cl:let ((__ros_arr_len 0))
    (cl:setf (cl:ldb (cl:byte 8 0) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) __ros_arr_len) (cl:read-byte istream))
  (cl:setf (cl:slot-value msg 'idx) (cl:make-array __ros_arr_len))
  (cl:let ((vals (cl:slot-value msg 'idx)))
    (cl:dotimes (i __ros_arr_len)
    (cl:setf (cl:aref vals i) (cl:make-instance 'geometry_msgs-msg:Point))
  (roslisp-msg-protocol:deserialize (cl:aref vals i) istream))))
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'LShapesIdxs) istream)
  (cl:let ((__ros_arr_len 0))
    (cl:setf (cl:ldb (cl:byte 8 0) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) __ros_arr_len) (cl:read-byte istream))
  (cl:setf (cl:slot-value msg 'LShapesPos) (cl:make-array __ros_arr_len))
  (cl:let ((vals (cl:slot-value msg 'LShapesPos)))
    (cl:dotimes (i __ros_arr_len)
    (cl:setf (cl:aref vals i) (cl:make-instance 'geometry_msgs-msg:Point))
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
  "c13d1b224cdf6df2f0e74d8c6705856a")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'AugmentedWhyConMsg)))
  "Returns md5sum for a message object of type 'AugmentedWhyConMsg"
  "c13d1b224cdf6df2f0e74d8c6705856a")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<AugmentedWhyConMsg>)))
  "Returns full string definition for message of type '<AugmentedWhyConMsg>"
  (cl:format cl:nil "Header header~%geometry_msgs/Pose[] poses~%geometry_msgs/Point nrDetectedLShapes~%geometry_msgs/Point[] idx~%geometry_msgs/Point LShapesIdxs~%geometry_msgs/Point[] LShapesPos~%geometry_msgs/Quaternion[] LShapesOri~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%# 0: no frame~%# 1: global frame~%string frame_id~%~%================================================================================~%MSG: geometry_msgs/Pose~%# A representation of pose in free space, composed of postion and orientation. ~%Point position~%Quaternion orientation~%~%================================================================================~%MSG: geometry_msgs/Point~%# This contains the position of a point in free space~%float64 x~%float64 y~%float64 z~%~%================================================================================~%MSG: geometry_msgs/Quaternion~%# This represents an orientation in free space in quaternion form.~%~%float64 x~%float64 y~%float64 z~%float64 w~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'AugmentedWhyConMsg)))
  "Returns full string definition for message of type 'AugmentedWhyConMsg"
  (cl:format cl:nil "Header header~%geometry_msgs/Pose[] poses~%geometry_msgs/Point nrDetectedLShapes~%geometry_msgs/Point[] idx~%geometry_msgs/Point LShapesIdxs~%geometry_msgs/Point[] LShapesPos~%geometry_msgs/Quaternion[] LShapesOri~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%# 0: no frame~%# 1: global frame~%string frame_id~%~%================================================================================~%MSG: geometry_msgs/Pose~%# A representation of pose in free space, composed of postion and orientation. ~%Point position~%Quaternion orientation~%~%================================================================================~%MSG: geometry_msgs/Point~%# This contains the position of a point in free space~%float64 x~%float64 y~%float64 z~%~%================================================================================~%MSG: geometry_msgs/Quaternion~%# This represents an orientation in free space in quaternion form.~%~%float64 x~%float64 y~%float64 z~%float64 w~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <AugmentedWhyConMsg>))
  (cl:+ 0
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'header))
     4 (cl:reduce #'cl:+ (cl:slot-value msg 'poses) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ (roslisp-msg-protocol:serialization-length ele))))
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'nrDetectedLShapes))
     4 (cl:reduce #'cl:+ (cl:slot-value msg 'idx) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ (roslisp-msg-protocol:serialization-length ele))))
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'LShapesIdxs))
     4 (cl:reduce #'cl:+ (cl:slot-value msg 'LShapesPos) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ (roslisp-msg-protocol:serialization-length ele))))
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
    (cl:cons ':LShapesPos (LShapesPos msg))
    (cl:cons ':LShapesOri (LShapesOri msg))
))
