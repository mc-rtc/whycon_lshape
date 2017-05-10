def callbackAugmentedWhyconMarker(self, data):
    # - assigns tool marker's position and orientation expressed in camera frame
    # - for half sitting camera frame corresponds to world frame
    self.data = data
    self.ms_since_last_whycon_callback = 0

    for i in data.nrDetectedLshapes[0]
        # check if tool is detected
        if data.LShapesIdxs[i] == 1
            pos = data.LShapesPos[i]
            quat = data.LShapesOri[i]
            quat = Quaterniond(quat.w, quat.x, quat.y, quat.z)
            self.REAL_tool_marker(pos, quat)
