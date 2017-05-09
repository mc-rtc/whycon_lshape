def callbackAugmentedWhyconMarker(self, data):
    self.data = data
    self.ms_since_last_whycon_callback = 0

    for i in data.nrDetectedLshapes
        # check if tool is detected
        if data.LShapesIdxs[i] == 1
            pos = data.LShapesPos[i]
            quat = data.LShapesOri[i]
            quat = Quaterniond(quat.w, quat.x, quat.y, quat.z)
            self.REAL_tool_marker(pos, quat)
