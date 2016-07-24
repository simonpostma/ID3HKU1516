#include "ofApp.h"
#include "Pad.h"
#include "Ball.h"

#define LEDA 11
#define LEDB 10
#define LEDC 9

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetFrameRate(60);
	gameState = 0;					// 0 = title, 1 = setup, 2 = game, 3 = game over
	color.set(0, 0, 0);
	lineColor.set(220, 220, 220);
	gameScore = 3;
	ledVal = 128;

	lose.loadSound("lose.wav");
	lose1.loadSound("lose1.wav");
	lose2.loadSound("lose2.wav");
	hit.loadSound("hit.wav");

	ofAddListener(arduino.EInitialized, this, &ofApp::setupArduino);
	arduinoIsLive = false;
	arduino.connect("COM8", 9600);

	arduino.sendPwm(LEDA, 0);
	arduino.sendPwm(LEDB, 0);
	arduino.sendPwm(LEDC, 0);
}

//--------------------------------------------------------------
void ofApp::update(){

	arduino.update(); 
	if (gameState == 2) {					// Update drawing of stuff during game state
		if (moveUp) {						// movement up
			pad.moveUp();
		}
		else if (moveDown) {				// movement down
			pad.moveDown();
		}
		ball.update();						// ball movement
		pad.update(arduino.getAnalog(0));
		if (gameScore == 3) {
			arduino.sendPwm(LEDA, ledVal);
			arduino.sendPwm(LEDB, ledVal);
			arduino.sendPwm(LEDC, ledVal);
		}
		else if (gameScore == 2) {
			arduino.sendPwm(LEDA, ledVal);
			arduino.sendPwm(LEDB, ledVal);
			arduino.sendPwm(LEDC, 0);
		}
		else if (gameScore == 1) {
			arduino.sendPwm(LEDA, ledVal);
			arduino.sendPwm(LEDB, 0);
			arduino.sendPwm(LEDC, 0);
		}
		else if (gameScore == 1) {
			arduino.sendPwm(LEDA, 0);
			arduino.sendPwm(LEDB, 0);
			arduino.sendPwm(LEDC, 0);
		}
	}
}

//--------------------------------------------------------------
void ofApp::draw(){
	ofBackground(160, 200, 160);
	ofSetColor(lineColor);
	ofDrawRectangle(0, 0, ofGetWidth(), 10);
	ofDrawRectangle(0, ((ofGetHeight() / 2) - 10), ofGetWidth(), 10);
	ofDrawRectangle(0, (ofGetHeight() - 10), ofGetWidth(), 10);
	ofDrawRectangle(0, 0, 10, ofGetHeight()); // links
	ofDrawRectangle(ofGetWidth() - 10, 0, 10, ofGetHeight()); // rechtds
	if (gameState == 0)					// State 0 Title screen
	{
		arduino.sendPwm(LEDA, 0);
		arduino.sendPwm(LEDB, 0);
		arduino.sendPwm(LEDC, 0);
		ofSetColor(color);
		ofDrawBitmapString("Solo Ping-Pong by Simon Postma", 20, 30);
		ofDrawBitmapString("Make sure you connected your Arduino before starting up!", 20, 60);
		ofDrawBitmapString("If you forgot to do so, close the program and connect your Arduino.", 20, 90);
		ofDrawBitmapString("Once connected, and started up, hit the Reset button on Arduino once.", 20, 120);
		ofDrawBitmapString("All done? Hit SPACEBAR to start.", 20, 150);
	}					
	if (gameState == 1)			// State 1 Game Setup
	{		
		pad.setup(arduino.getAnalog(0));
		ball.setup();
		moveUp = false;
		moveDown = false;
		gameState = 2;
		scoreString = std::to_string(gameScore);
	}
	if (gameState == 2)			// State 2 game Playing
	{

		ofSetColor(color);
		ofDrawBitmapString("Lives: " + scoreString, ofGetWidth() - 80, 25);
		ball.draw();						// draw ball
		pad.draw();							// draw pad


		if (ball.x < 30)	// collision
		{
			if (ball.y > pad.y - (pad.height / 2) && ball.y < pad.y + (pad.height / 2))
			{
				hit.play();
				ball.speedX = -ball.speedX;
				ball.speedX += ofRandom(1, 2);
				ball.speedY += ofRandom(-1, 1);
			}
		}
		if (ball.x < 0) {					// score event
			if (gameScore > 1)
			{
				if (gameScore == 3)
				{
					lose2.play();
				}
				else if (gameScore == 2)
				{
					lose1.play();
				}
				gameScore -= 1;
				gameState = 1;
			}
			else if (gameScore == 1)		// running out of lives
			{
				lose.play();
				gameState = 3;

			}
		}
	}
	else if (gameState == 3) {		// Game actief vanuit state 1
		arduino.sendPwm(LEDA, 0);
		arduino.sendPwm(LEDB, 0);
		arduino.sendPwm(LEDC, 0);
		ofSetColor(color);
		ofDrawBitmapString("Game Over!", 20, 30);
		ofDrawBitmapString("Hit spacebar to restart.", 20, 60);
		gameScore = 3;
	}
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	if (gameState == 0)					// State 0 Title screen
	{
		if (key == ' ') {
			gameState = 1;
		}
	}
	if (gameState == 1)					// State 0 Game Setup
	{
	}
	if (gameState == 2)					// State 0 Game Playing
	{
		if (key == OF_KEY_UP) {
			moveUp = true;
		}
		else if (key == OF_KEY_DOWN) {
			moveDown = true;
		}
	}
	if (gameState == 3)					// State 0 Game Over
	{
		if (key == ' ') {
			gameState = 1;
		}
	}



}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
	if (key == OF_KEY_UP) {
		moveUp = false;
	}

	else if (key == OF_KEY_DOWN) {
		moveDown = false;
	}
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}

void ofApp::exit()
{
	arduino.sendPwm(LEDA, 0);
	arduino.sendPwm(LEDB, 0);
	arduino.sendPwm(LEDC, 0);
	arduino.disconnect();
}

void ofApp::setupArduino(const int& version)
{
	//remove eventhandler
	ofRemoveListener(arduino.EInitialized, this, &ofApp::setupArduino);
	//arduino alive and kicking
	arduinoIsLive = true;

	//pinmodes
	arduino.sendDigitalPinMode(LEDA, ARD_PWM);
	arduino.sendDigitalPinMode(LEDB, ARD_PWM);
	arduino.sendDigitalPinMode(LEDC, ARD_PWM);
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
