#include "Ball.h"

Ball::Ball(){

}

void Ball::setup(){
    x = ofRandom(500, ofGetWidth());      // give some random positioning
    y = ofRandom(0, ofGetHeight());

	speedX = 7;           // and random speed and direction
    speedY = ofRandom(0, 6);

    radius = 25;
    color.set(255, 255, 255); // one way of defining digital color is by adddressing its 3 components individually (Red, Green, Blue) in a value from 0-255, in this example we're setting each to a random value
	shadow.set(0, 0, 0);
	bounce.loadSound("bounce.wav");
}


void Ball::update(){
	if(x > ofGetWidth()){
		bounce.play();
        x = ofGetWidth();
		speedX *= -1;
		speedX += ofRandom(-1, 0);
		speedY += ofRandom(-5, 5);

    }

    if(y < 0 ){
        y = 0;
		bounce.play();
        speedY *= -1;
		speedY += ofRandom(-1, 1);
    } else if(y > ofGetHeight()){
		bounce.play();
        y = ofGetHeight();
		speedY *= -1;
		speedY += ofRandom(-1, 1);
    }

    x+=speedX;
    y+=speedY;
}

void Ball::draw(){
	ofSetColor(shadow);
	ofCircle((x + 4), (y + 4), radius);
	ofSetColor(color);
    ofCircle(x, y, radius);
}