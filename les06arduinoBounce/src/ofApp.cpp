#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
	ball.setup();
	ball.ard = &arduino;

	ofAddListener(arduino.EInitialized, this, &ofApp::setupArduino);
	arduinoIsLive = false;
	arduino.connect("COM8", 9600);
}

//--------------------------------------------------------------
void ofApp::update() {
	//if (arduinoIsLive)
	//{
		arduino.update();
		ball.arduinoConnected = arduinoIsLive;
		ball.update(arduino.getAnalog(0));
	//}
}

//--------------------------------------------------------------
void ofApp::draw() {
	ball.draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key) {

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ) {

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

void ofApp::exit()
{
	arduino.disconnect();
}

void ofApp::setupArduino(const int& version)
{
	//remove eventhandler
	ofRemoveListener(arduino.EInitialized, this, &ofApp::setupArduino);
	//arduino alive and kicking
	arduinoIsLive = true;

	//pinmodes
	arduino.sendAnalogPinReporting(0, ARD_ANALOG);

	//event handlers for pins
	//ofAddListener(arduino.EDigitalPinChanged, this, &ofApp::digitalPinChanged);
	//ofAddListener(arduino.EAnalogPinChanged, this, &ofApp::analogPinChanged);
}

void ofApp::digitalPinChanged(const int& pinNum) {
	// get value with arduino.getDigital(pinNum)
}

void ofApp::analogPinChanged(const int& pinNum) {
	// get value with arduino.getAnalog(pinNum));
}
