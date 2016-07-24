#include "Pad.h"

Pad::Pad() {
}

void Pad::setup() {

	x = 15;
	y = ofGetHeight() / 2;

	speedY = 10;

	width = 15;
	height = 80;

	color.set(0, 0, 0);
}

void Pad::draw()
{
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