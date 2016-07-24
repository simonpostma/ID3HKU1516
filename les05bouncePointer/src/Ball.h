#pragma once //zelfde als ifndef

#ifndef _BALL //zelfde als ^
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

private:

};
#endif