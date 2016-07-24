#pragma once

#include "ofMain.h"

class Pad {

public:

	Pad();

	void setup();
	void draw();
	void moveUp();
	void moveDown();

	// variables
	float x;
	float y;
	float speedY;

	ofColor color;

	int width;
	int height;
	int gamestate;
};