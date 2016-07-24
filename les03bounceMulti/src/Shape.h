#ifndef _SHAPE
#define _SHAPE

#include "ofMain.h"

class Shape {

public:

	Shape();

    void setup();
    void update();
    void drawCircle();
	void drawTriangle();
	void drawRectangle();

    // variables
    float x;
    float y;
    float speedY;
    float speedX;
    int radius;
	int rectSize;
    ofColor color;

private:

};
#endif
