#pragma once

#include "ofMain.h"
#include "ofxGui.h"

#include "Planet.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();
		void keyPressed(int key);

    ofxPanel gui;
	ofImage imgEarth;
	ofImage imgSun;
	ofImage imgMoon;

    ofParameterGroup planetParams;

    Planet planet01;
    Planet planet02;
	Planet planet03;

    ofLight light;

    bool drawGrid;
    bool drawLight;

    ofEasyCam cam;

};
