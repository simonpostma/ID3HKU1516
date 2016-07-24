#pragma once
#define _PAD
#include "ofMain.h"

class Pad {

public:

	Pad();

	void setup(int mod);
	void update(int mod);
	void draw();
	void moveUp();
	void moveDown();

	// variables
	float x;
	float y;
	float speedY;

	ofColor color;
	ofColor shadow;

	int width;
	int height;
	int gamestate;
};