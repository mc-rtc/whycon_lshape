
(cl:in-package :asdf)

(defsystem "augmented_whycon-msg"
  :depends-on (:roslisp-msg-protocol :roslisp-utils :geometry_msgs-msg
               :std_msgs-msg
)
  :components ((:file "_package")
    (:file "WhyconMarker" :depends-on ("_package_WhyconMarker"))
    (:file "_package_WhyconMarker" :depends-on ("_package"))
    (:file "AugmentedWhyConMsg" :depends-on ("_package_AugmentedWhyConMsg"))
    (:file "_package_AugmentedWhyConMsg" :depends-on ("_package"))
  ))