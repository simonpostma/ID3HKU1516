#include "Ball.h"

Ball::Ball() {}

void Ball::setup()
{
    x = ofRandom(0, ofGetWidth());
    y = ofRandom(0, ofGetHeight());

    speedX = ofRandom(-30, 30);
    speedY = ofRandom(-30, 30);

    radius = 150;

    color.set(ofRandom(255),ofRandom(255),ofRandom(255));
}

void Ball::update()
{
	if (x < 0 )
	{
        x = 0;
        speedX *= -1;
	}
	else if (x > ofGetWidth())
	{
        x = ofGetWidth();
        speedX *= -1;
    }

    if (y < 0 )
	{
        y = 0;
        speedY *= -1;
    }
	else if (y > ofGetHeight())
	{
        y = ofGetHeight();
        speedY *= -1;
    }

    x+=speedX;
    y+=speedY;
}

void Ball::draw()
{
    ofSetColor(color);
    ofCircle(x, y, radius);
}