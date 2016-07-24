#include "Ball.h"

Ball::Ball()
{

}

void Ball::setup()
{
    x = ofRandom(0, ofGetWidth());      // give some random positioning
    y = ofRandom(0, ofGetHeight());

    speedX = ofRandom(-50, 50);           // and random speed and direction
    speedY = ofRandom(-50, 50);

    radius = 80;

    color.set(ofRandom(255),ofRandom(255),ofRandom(255)); // one way of defining digital color is by adddressing its 3 components individually (Red, Green, Blue) in a value from 0-255, in this example we're setting each to a random value
}

void Ball::update(int mod)
{
	if (x < 0 )
	{
        x = 0;
        speedX *= -1;
		color.set(ofRandom(255), ofRandom(255), ofRandom(255));
	}
	else if (x > ofGetWidth())
	{
        x = ofGetWidth();
        speedX *= -1;
		color.set(ofRandom(255), ofRandom(255), ofRandom(255));
    }

    if (y < 0 )
	{
        y = 0;
        speedY *= -1;
		color.set(ofRandom(255), ofRandom(255), ofRandom(255));
    }
	else if (y > ofGetHeight())
	{
        y = ofGetHeight();
        speedY *= -1;
		color.set(ofRandom(255), ofRandom(255), ofRandom(255));
    }

    x+=(speedX / 1024 * mod);
    y+=(speedY / 1024 * mod);
}

void Ball::draw()
{
    ofSetColor(color);
    ofCircle(x, y, radius);
}