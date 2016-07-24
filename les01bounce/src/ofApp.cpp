#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
	// kies random start coordinaten
	x = ofRandom(0, ofGetWidth());
	y = ofRandom(0, ofGetHeight());
	x1 = ofRandom(0, ofGetWidth());
	y1 = ofRandom(0, ofGetHeight());
	x2 = ofRandom(0, ofGetWidth());
	y2 = ofRandom(0, ofGetHeight());

	// random snelheid
	speedX = ofRandom(-10, 10);
	speedY = ofRandom(-10, 10);
	speedX1 = ofRandom(-10, 10);
	speedY1 = ofRandom(-10, 10);
	speedX2 = ofRandom(-10, 10);
	speedY2 = ofRandom(-10, 10);

	// grootte van cirkel
	radius = ofRandom(10, 70);
	radius1 = ofRandom(10, 70);
	radius2 = ofRandom(10, 70);

	color.set(ofRandom(255), ofRandom(255), ofRandom(255));
	color1.set(ofRandom(255), ofRandom(255), ofRandom(255));
	color2.set(ofRandom(255), ofRandom(255), ofRandom(255));
}

//--------------------------------------------------------------
void ofApp::update() {

	// links/ rechts tegen de rand aan? keer om!
	if (x < 0) {
		x = 0;
		speedX = -speedX;
	}
	else if (x > ofGetWidth()) {
		x = ofGetWidth();
		speedX = -speedX;
	}
	if (x1 < 0) {
		x1 = 0;
		speedX1 = -speedX1;
	}
	else if (x1 > ofGetWidth()) {
		x1 = ofGetWidth();
		speedX1 = -speedX1;
	}
	if (x2 < 0) {
		x2 = 0;
		speedX2 = -speedX2;
	}
	else if (x2 > ofGetWidth()) {
		x2 = ofGetWidth();
		speedX2 = -speedX2;
	}

	// boven/onder tegen de rand aan? keer om!
	if (y < 0) {
		y = 0;
		speedY = -speedY;
	}
	else if (y > ofGetHeight()) {
		y = ofGetHeight();
		speedY = -speedY;
	}
	if (y1 < 0) {
		y1 = 0;
		speedY1 = -speedY1;
	}
	else if (y1 > ofGetHeight()) {
		y1 = ofGetHeight();
		speedY1 = -speedY1;
	}
	if (y2 < 0) {
		y2 = 0;
		speedY2 = -speedY2;
	}
	else if (y2 > ofGetHeight()) {
		y2 = ofGetHeight();
		speedY2 = -speedY2;
	}

	// bereken nieuwe coordinaten
	x += speedX;
	y += speedY;
	x1 += speedX1;
	y1 += speedY1;
	x2 += speedX2;
	y2 += speedY2;
}

//--------------------------------------------------------------
void ofApp::draw() {
	ofSetColor(color);
	ofCircle(x, y, radius);
	ofSetColor(color1);
	ofCircle(x1, y1, radius1);
	ofSetColor(color2);
	ofCircle(x2, y2, radius2);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key) {

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h) {

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg) {

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo) {

}