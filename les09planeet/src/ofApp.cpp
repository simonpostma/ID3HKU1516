#include "ofApp.h"

void ofApp::setup(){
    ofSetFrameRate(60);
    ofBackground(30,30,30);

	gui.setup();

    drawGrid = false;
    drawLight = false;

    planet01.setup("Sun");
    planetParams.add(planet01.planetParamGroup);
	imgSun.load("sun.jpg");

    planet02.setup("Earth");
    planetParams.add(planet02.planetParamGroup);
	imgEarth.load("earth.jpg");
	
	planet03.setup("Moon");
	planetParams.add(planet03.planetParamGroup);
	imgMoon.load("moon.jpg");

	gui.add(planetParams);
	
    // plaats een light in de 3d ruimte
    light.setPointLight();
    light.setPosition(200,200,200);
	
	ofEnableDepthTest();
}

void ofApp::update(){
    planet01.update();
    planet02.update();
	planet03.update();
}

void ofApp::draw(){
	gui.draw();

	glMatrixMode(GL_TEXTURE);
	glPushMatrix();
	ofScale(imgEarth.getWidth(), imgEarth.getHeight());
	glMatrixMode(GL_MODELVIEW);

	ofEnableDepthTest();

    // zorg ervoor dat OF rekening houdt met de 'diepte' (z-coord) van alle objecten
    // start de camera
    cam.begin();

    // als je een camera gebruikt, hoef je geen translate te doen
    // om het 0-punt naar het midden van 't scherm te verplaatsen
    if (drawGrid) ofDrawGrid(200);
    if (drawLight) light.draw();
   
	// teken de zon
	imgSun.bind();
	planet01.draw();
	imgSun.unbind();
    
    // teken de aarde
	ofTranslate(planet01.distance, 500);
	imgEarth.bind();
	planet02.draw();
	imgEarth.unbind();
	
	// teken de maan
	ofTranslate(planet02.distance, 200);
	imgMoon.bind();
	planet03.draw();
	imgMoon.unbind();

    // eindig het camera blok
    cam.end();
	ofDisableDepthTest();

    // schakel de diepte-test weer uit
	glMatrixMode(GL_TEXTURE);
	glPopMatrix();
	glMatrixMode(GL_MODELVIEW);
}

void ofApp::keyPressed(int key) {
    if (key=='g') {
        drawGrid = !drawGrid;
    } else if (key=='l') {
        drawLight = !drawLight;
    }
}
