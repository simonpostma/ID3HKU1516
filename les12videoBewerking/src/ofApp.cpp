#include "ofApp.h"

void ofApp::setup() {
    grabber.setDeviceID(0);
    grabber.initGrabber(CAM_WIDTH, CAM_HEIGHT);
    grabber.setDesiredFrameRate(30);

    workspace.allocate(CAM_WIDTH, CAM_HEIGHT, OF_IMAGE_COLOR);
}

void ofApp::update() {
    grabber.update();

    if (grabber.isFrameNew()) {
        ofPixels pixels = grabber.getPixelsRef();

        for (int y=0; y<pixels.getHeight(); y++) {
            for (int x=0; x<pixels.getWidth(); x++) {
                ofColor col = pixels.getColor( x, y );

		col.g = 255 - col.g;

                workspace.setColor( x, y, col );
            }
        }

        image.setFromPixels( workspace );
        image.mirror(false,true);
		image.rotate90(1);
    }
}

void ofApp::draw() {
    ofSetColor(255, 255, 255);
    image.draw(0, 0, ofGetWidth(), ofGetHeight());
}