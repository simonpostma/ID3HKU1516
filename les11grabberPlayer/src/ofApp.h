#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp {

public:
	void setup();
	void update();
	void draw();

	ofVideoGrabber grabber;
	ofVideoPlayer video;
	ofSoundPlayer liedje;
};