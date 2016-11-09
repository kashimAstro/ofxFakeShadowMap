#include "ofApp.h"

void ofApp::setup()
{
	ofSetSmoothLighting(true);
	pointLight.setDiffuseColor( ofColor(255.f, 255.f, 255.f));
	pointLight.setSpecularColor( ofColor(255.f, 255.f, 255.f));
	material.setShininess( 64 );

	shadow.setup();
	shadow.setColors(ofColor(0,0,0));
	shadow.setAlpha(255);

	model.loadModel("model.dae",true);
	gui.setup();
	gui.add(dir.set("direction light",
	    ofVec3f(1,-2,2),
	    ofVec3f(-10),
	    ofVec3f(10)
	));
	cam.setVFlip(true);
}

void ofApp::update()
{
	ofSetWindowTitle(ofToString(ofGetFrameRate()));
	shadow.setDirLight(dir);
	
	pointLight.setPosition(
		ofMap(dir->x,0,10,0,1000),
		ofMap(dir->y,0,10,0,1000),
		ofMap(dir->z,0,10,0,1000)
	);
}

void ofApp::render(bool color)
{
	ofPushMatrix();
	if(color) ofSetColor(ofColor::red);
	model.drawFaces();
	if(color) ofSetColor(ofColor::yellow);
	ofDrawBox(200,-100,0,100,100,100);
	if(color) ofSetColor(ofColor::green);
	ofDrawCone(-200, -80, -30, 50, 120);
	if(color) ofSetColor(ofColor::grey);
	ofDrawCylinder(-100, -70, 130, 50, 180);
	ofPopMatrix();
}

void ofApp::draw()
{
	ofEnableDepthTest();
	cam.begin();
	
	ofEnableLighting();

	ofSetColor(pointLight.getDiffuseColor());
	ofDrawSphere(pointLight.getPosition(), 20.f);

	pointLight.enable();
	material.begin();
	render(true);
	material.end();
	pointLight.disable();
	ofDisableLighting();

	shadow.begin(cam);
		render(false);
	shadow.end();

	ofPushMatrix();
	ofRotateX(90);	
	ofSetColor(0,0,200);
	ofDrawPlane(0,0,-1,1500,1500);
	ofPopMatrix();
	
	cam.end();
	ofDisableDepthTest();

	gui.draw();
}
