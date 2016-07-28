#pragma once

#include "ofMain.h"

class Planet
{
    public:
        Planet();
        virtual ~Planet();
        void setup(string name);
        void update();
        void draw();

    float rotation;
	ofParameterGroup planetParamGroup;
	ofParameter<float> rotateSpeed;
	ofParameter<float> distance;
};
