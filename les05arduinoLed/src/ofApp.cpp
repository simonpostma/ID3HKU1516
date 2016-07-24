#include "ofApp.h"

#define LEDPIN 11
#define BUTPIN 4

//--------------------------------------------------------------
void ofApp::setup() {

	ofAddListener(arduino.EInitialized, this, &ofApp::setupArduino);
	ofAddListener(arduino.EDigitalPinChanged, this, &ofApp::digitalPinChanged);
	arduinoIsLive = false;

	arduino.connect("COM8", 9600);
	lightOn = true;
	ledVal = 128;
}

//--------------------------------------------------------------
void ofApp::update() {
	arduino.update();
}

//--------------------------------------------------------------
void ofApp::draw() {
	if (arduino.getDigital(BUTPIN)) {
		ofClear(0);
		ofDrawBitmapString("Thanks!", 10, 10);
	}
	else {
		ofClear(0);
		ofDrawBitmapString("Push me or else!", 10, 10);
	}
	arduino.sendPwm(LEDPIN, ledVal);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {
	if (key == 'l') {
		if (lightOn == true) {
			lightOn = false;
			ledVal = 0;

		}
		else { 
			lightOn = true;
			ledVal = 128;
		}
	}
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

void ofApp::exit()
{
	arduino.disconnect();
}

void ofApp::setupArduino(const int& version)
{
	//remove eventhandler
	ofRemoveListener(arduino.EInitialized, this, &ofApp::setupArduino);

	//debug logging
	//	ofLog(OF_LOG_NOTICE,"Arduino found: %s", arduino.getFirmwareName());
	//  ofLog(OF_LOG_NOTICE,"Firmata v%s.%s", arduino.getMajorFirmwareVersion(), arduino.getMinorFirmwareVersion());


	//arduino alive and kicking
	arduinoIsLive = true;

	//pinmodes
	arduino.sendDigitalPinMode(LEDPIN, ARD_PWM);
	arduino.sendDigitalPinMode(BUTPIN, ARD_INPUT);

	//event handlers for pins
	ofAddListener(arduino.EDigitalPinChanged, this, &ofApp::digitalPinChanged);
	ofAddListener(arduino.EAnalogPinChanged, this, &ofApp::analogPinChanged);
}

void ofApp::digitalPinChanged(const int& pinNum) {
	// get value with arduino.getDigital(pinNum)
}

void ofApp::analogPinChanged(const int& pinNum) {
	// get value with arduino.getAnalog(pinNum));
}