#include "Ball.h"

Ball::Ball(){

}

void Ball::setup(){
    x = ofRandom(500, ofGetWidth());      // give some random positioning
    y = ofRandom(0, ofGetHeight());

    speedX = ofRandom(8, 12);           // and random speed and direction
    speedY = ofRandom(0, 10);

    radius = 25;
    color.set(ofRandom(255),ofRandom(255),ofRandom(255)); // one way of defining digital color is by adddressing its 3 components individually (Red, Green, Blue) in a value from 0-255, in this example we're setting each to a random value

	bounce.loadSound("bounce.wav");
}


void Ball::update(){
	if(x > ofGetWidth()){
		bounce.play();
        x = ofGetWidth();
		speedX *= -1;
		speedX += ofRandom(-1, 3);
		speedY += ofRandom(0.5, 0.5);
    }

    if(y < 0 ){
        y = 0;
		bounce.play();
        speedY *= -1;
		speedY += ofRandom(-1, 3);
		speedY += ofRandom(0.5, 0.5);
    } else if(y > ofGetHeight()){
		bounce.play();
        y = ofGetHeight();
		speedY *= -1;
		speedY += ofRandom(-1, 3);
		speedY += ofRandom(-0.5, 0.5);
    }

    x+=speedX;
    y+=speedY;
}

void Ball::draw(){
    ofSetColor(color);
    ofCircle(x, y, radius);
}