#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(60);
	ofSetWindowTitle("openframeworks");

	ofBackground(239);
	ofSetLineWidth(3);
	ofSetRectMode(ofRectMode::OF_RECTMODE_CENTER);
	ofEnableDepthTest();
}

//--------------------------------------------------------------
void ofApp::update() {

	ofSeedRandom(39);
}

//--------------------------------------------------------------
void ofApp::draw() {

	auto size = 60;
	for (int x = size * 0.5; x <= ofGetWidth(); x += size) {

		for (int y = size * 0.5; y <= ofGetHeight(); y += size) {

			ofPushMatrix();
			ofTranslate(x, y);

			auto noise_value = ofNoise(x * 0.005, y * 0.005, ofGetFrameNum() * 0.005);
			auto rotate_x = 0;
			if (noise_value < 0.25) {

				rotate_x = ofMap(noise_value, 0, 0.25, -180, 0);
			}
			else if (noise_value > 0.75) {

				rotate_x = ofMap(noise_value, 0.75, 1.0, 0, 180);
			}
			ofRotateX(rotate_x);			

			ofFill();
			ofSetColor(39);
			ofDrawRectangle(0, 0, size - 1.5, size - 1.5);

			ofNoFill();
			ofSetColor(239);
			ofDrawRectangle(0, 0, size, size);

			ofPopMatrix();
		}
	}
}

//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}