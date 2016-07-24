#include "ofApp.h"
#include "Pad.h"
#include "Ball.h"

Ball ball;


//--------------------------------------------------------------
void ofApp::setup(){
	gameState = 0;					// 0 = title, 1 = setup, 2 = game, 3 = game over
	color.set(0, 0, 0);
	gameScore = 3;

	lose.loadSound("lose.wav");
	lose1.loadSound("lose1.wav");
	lose2.loadSound("lose2.wav");
	hit.loadSound("hit.wav");
}

//--------------------------------------------------------------
void ofApp::update(){
 
	if (gameState == 2) {					// Update drawing of stuff during game state
		if (moveUp) {						// movement up
			pad.moveUp();
		}
		else if (moveDown) {				// movement down
			pad.moveDown();
		}
		ball.update();						// ball movement
	}
}

//--------------------------------------------------------------
void ofApp::draw(){
	ofBackground(255, 255, 255);
	if (gameState == 0)					// State 0 Title screen
	{
		ofSetColor(color);
		ofDrawBitmapString("Pong", (ofGetWidth() / 2) - 20, ofGetHeight() / 2);
		ofDrawBitmapString("Hit spacebar to start.", (ofGetWidth() / 2) - 70, (ofGetHeight() / 2) + 20);
	}					
	else if (gameState == 1)			// State 1 Game Setup
	{		
		pad.setup();
		ball.setup();

		moveUp = false;
		moveDown = false;
		padding = 30;
		gameState = 2;
		scoreString = std::to_string(gameScore);
	}
	else if (gameState == 2)			// State 2 game Playing
	{
		ofSetColor(color);
		ofDrawBitmapString("Lives: " + scoreString, ofGetWidth() - 100, 10);
		pad.draw();							// draw pad
		ball.draw();						// draw ball
		if (ball.x < pad.x + (pad.width))	// collision
		{
			if (ball.y > pad.y - (pad.height / 2) && ball.y < pad.y + (pad.height / 2))
			{
				hit.play();
				ball.speedX = -ball.speedX;
				ball.speedX += ofRandom(-1, 3);
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
		ofSetColor(color);
		ofDrawBitmapString("Game Over!", (ofGetWidth() / 2) -20, ofGetHeight() / 2);
		ofDrawBitmapString("Hit spacebar to restart.", (ofGetWidth() / 2) - 70, (ofGetHeight() / 2) + 20);
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
