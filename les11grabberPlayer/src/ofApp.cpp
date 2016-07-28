#include "ofApp.h"

void ofApp::setup() {
	ofBackground(255, 255, 255);
	ofSetVerticalSync(true);

	//grabber.setVerbose(true);
	grabber.listDevices();
	grabber.setDeviceID(0);
	grabber.setDesiredFrameRate(30);
	grabber.initGrabber(320, 240);

	video.loadMovie("bendershort.mp4");
	video.setVolume(0);
	video.play();
	video.setLoopState(OF_LOOP_NORMAL);

	liedje.loadSound("audio.mp3");
	liedje.setLoop(true); //Sound will loop
	liedje.play();
}

void ofApp::update() {
	grabber.update();
	video.update();
}

void ofApp::draw() {
	ofSetColor(ofColor::white);		// grabber
	grabber.draw(0, 0, ofGetWidth(), ofGetHeight());

	ofSetColor(255, 51, 204, 180);
	video.draw(0, 0, ofGetWidth(), ofGetHeight());
}
