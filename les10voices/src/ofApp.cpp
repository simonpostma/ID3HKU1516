#include "ofApp.h"

void ofApp::setup() {
	//    ofSetLogLevel(OF_LOG_VERBOSE);
	ofSetLogLevel(OF_LOG_NOTICE);
	//    ofSetLogLevel(OF_LOG_SILENT);

	for (int i = 0; i<VOICES; i++) {
		voicePaused[i] = true;

		ofLogNotice() << "Loading voice " << i << endl;
		voicePlayer[i].loadSound("vox" + ofToString(i + 1) + ".wav");
		voicePlayer[i].setLoop(true);

		//voicePlayer[i].setVolume(1);
		voicePlayer[i].play();
		voicePlayer[i].setPaused(true);
	}

	ofSoundSetVolume(0.2);
}

void ofApp::update() {
	float time = ofGetElapsedTimef();

	float x = time*0.1 + 30;
	for (int i = 0; i<VOICES; i++) {
		float y = i * 0.02;
		float volume = ofNoise(x, y);
		voicePlayer[i].setVolume(volume);
	}

	ofSoundUpdate();
}

void ofApp::draw() {
	ofBackground(30, 30, 30);
	for (int i = 0; i<VOICES; i++) {
		if (!voicePaused[i]) {

			// bereken een kleur
			ofSetColor(i * 20 + 128, i * 80, i * 10 + 60);

			// teken voor iedere stem een balkje, met als lengte het volume, en 5 px hoog
			ofRect(100, i * 30 + 200, voicePlayer[i].getVolume() * 300, 5);
		}
	}
}

void ofApp::keyPressed(int key) {
	ofLogVerbose() << "Key:" << key << endl;

	// afhankelijk van de toets, zet een stem aan of uit
	if (key == '1') {
		voicePaused[0] = !voicePaused[0];
		voicePlayer[0].setPaused(voicePaused[0]);
	}
	else if (key == '2') {
		voicePaused[1] = !voicePaused[1];
		voicePlayer[1].setPaused(voicePaused[1]);
	}
	else if (key == '3') {
		voicePaused[2] = !voicePaused[2];
		voicePlayer[2].setPaused(voicePaused[2]);
	}
	else if (key == '4') {
		voicePaused[3] = !voicePaused[3];
		voicePlayer[3].setPaused(voicePaused[3]);
	}
	else if (key == '5') {
		voicePaused[4] = !voicePaused[4];
		voicePlayer[4].setPaused(voicePaused[4]);
	}
	else if (key == '6') {
		voicePaused[5] = !voicePaused[5];
		voicePlayer[5].setPaused(voicePaused[5]);
	}
	else if (key == 'q') {
		voicePlayer[0].setSpeed(2.0f);
	}
	else if (key == 'w') {
		voicePlayer[1].setSpeed(2.0f);
	}
	else if (key == 'e') {
		voicePlayer[2].setSpeed(2.0f);
	}
	else if (key == 'r') {
		voicePlayer[3].setSpeed(2.0f);
	}
	else if (key == 't') {
		voicePlayer[4].setSpeed(2.0f);
	}
	else if (key == 'y') {
		voicePlayer[5].setSpeed(2.0f);
	}
	else if (key == 'a') {
		voicePlayer[0].setSpeed(1.0f);
	}
	else if (key == 's') {
		voicePlayer[1].setSpeed(1.0f);
	}
	else if (key == 'd') {
		voicePlayer[2].setSpeed(1.0f);
	}
	else if (key == 'f') {
		voicePlayer[3].setSpeed(1.0f);
	}
	else if (key == 'g') {
		voicePlayer[4].setSpeed(1.0f);
	}
	else if (key == 'h') {
		voicePlayer[5].setSpeed(1.0f);
	}
	else if (key == 'z') {
		voicePlayer[0].setSpeed(0.2f);
	}
	else if (key == 'x') {
		voicePlayer[1].setSpeed(0.2f);
	}
	else if (key == 'c') {
		voicePlayer[2].setSpeed(0.2f);
	}
	else if (key == 'v') {
		voicePlayer[3].setSpeed(0.2f);
	}
	else if (key == 'b') {
		voicePlayer[4].setSpeed(0.2f);
	}
	else if (key == 'n') {
		voicePlayer[5].setSpeed(0.2f);
	}
	else if (key == '[') {
		for (int i = 0; i < VOICES; i++) { voicePlayer[i].setPan(-1.0f); }
	}
	else if (key == ']') {
		for (int i = 0; i < VOICES; i++) { voicePlayer[i].setPan(1.0f); }
	}
	else if (key == ' ') {
		for (int i = 0; i < VOICES; i++) { voicePlayer[i].setPan(0.0f); }
	}
}