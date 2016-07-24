#pragma once

#include "ofMain.h"
#include "Pad.h"
#include "Ball.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
		void exit();

		void setupArduino(const int & version);
		void digitalPinChanged(const int & pinNum);
		void analogPinChanged(const int & pinNum);

		bool moveUp;
		bool moveDown;
		int gameState;
		int gameScore;
		int ledVal;
		bool arduinoIsLive;

		string scoreString;

		ofColor color;
		ofColor lineColor;

		ofSoundPlayer lose;
		ofSoundPlayer lose1;
		ofSoundPlayer lose2;
		ofSoundPlayer hit;

		Pad pad;
		Ball ball;
		
		ofArduino arduino;


};
