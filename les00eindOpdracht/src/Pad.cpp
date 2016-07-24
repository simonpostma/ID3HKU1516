#include "Pad.h"

Pad::Pad() {
}

void Pad::setup(int mod) {

	x = 15;
	y = mod;

	speedY = 10;

	width = 15;
	height = 90;

	color.set(200, 60, 60);
	shadow.set(0, 0, 0);
}

void Pad::update(int mod) {
	y = mod;
	if (y > (ofGetHeight() - 45)) { y = ofGetHeight() - 45; }
	if (y < 45) { y = 45; }
}

void Pad::draw()
{
	ofSetColor(shadow);
	ofDrawRectangle((x+3), (y+2) - (height / 2), width, height);
	ofSetColor(color);
	ofDrawRectangle(x, y - (height / 2), width, height);
}

void Pad::moveUp()
{
	if (y - speedY >= height / 2)
	{
		y = y - speedY;
	}
}

void Pad::moveDown() {
	if (y + speedY <= ofGetHeight() - (height / 2)) {
		y = y + speedY;
	}
}