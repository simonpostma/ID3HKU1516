#include "ofApp.h"


//--------------------------------------------------------------
void ofApp::setup() {
    for (int i=0; i<5; i++) {									// Fill the Circles vector
        Shape newShape;
		newShape.setup();
		circles.push_back(newShape);
    }
	for (int i = 0; i<3; i++) {									// Fill the Triangles vector
		Shape newShape;
		newShape.setup();
		triangles.push_back(newShape);
	}
	for (int i = 0; i<2; i++) {									// Fill the Rectangles vector
		Shape newShape;
		newShape.setup();
		rectangles.push_back(newShape);
	}
}

//--------------------------------------------------------------
void ofApp::update() {
	for (int i = 0; i < circles.size(); i++) {					// Update the circles
		circles[i].update();
	}
	for (int i = 0; i < triangles.size(); i++) {				// Update the Triangles
		triangles[i].update();
	}
	for (int i = 0; i < rectangles.size(); i++) {				// Update the Rectangles
		rectangles[i].update();
	}
}

//--------------------------------------------------------------
void ofApp::draw() {
    for (int i=0; i<circles.size(); i++) {
		circles[i].drawCircle();
    }
	for (int i = 0; i<triangles.size(); i++) {
		triangles[i].drawTriangle();
	}
	for (int i = 0; i<rectangles.size(); i++) {
		rectangles[i].drawRectangle();
	}
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key) {

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ) {

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h) {

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg) {

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo) {

}
