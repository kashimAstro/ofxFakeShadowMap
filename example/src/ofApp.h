#pragma once

#include "ofMain.h"
#include "ofxAssimpModelLoader.h"
#include "ofxFakeShadowMap.h"
#include "ofxGui.h"

class ofApp : public ofBaseApp{
	public:
		void setup();
		void update();
		void draw();
		void render(bool color);

		ofxAssimpModelLoader model;
                ofxFakeShadowMap shadow;
                ofEasyCam cam;
                ofLight pointLight;
                ofMaterial material;

                ofxPanel gui;
                ofParameter<ofVec3f> dir;

};
