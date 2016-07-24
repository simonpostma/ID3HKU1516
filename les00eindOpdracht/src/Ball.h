#pragma once
#define _BALL
#include "ofMain.h"

class Ball {

public:

    Ball();

    void setup();
    void update();
    void draw();

    // variables
    float x;
    float y;
    float speedY;
    float speedX;
    int radius;
    ofColor color;
	ofColor shadow;

	ofSoundPlayer bounce;

private:

};