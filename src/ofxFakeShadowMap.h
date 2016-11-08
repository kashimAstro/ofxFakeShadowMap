#include "ofMain.h"

class ofxFakeShadowMap{
	public:
		float alpha;
		ofVec3f lightDir;

		void setup()
		{
			alpha = 155;
			lightDir = ofVec3f(1,2,2);
		}

		void setDirLight(ofVec3f _ld)
		{
			lightDir = _ld;
		}

		void setAlpha(float _a)
		{
			alpha = _a;
		}

		void begin()
		{
			ofPushStyle();
                        ofVec3f lightRay = lightDir;
			if(lightRay.y == 0) lightRay.y = 1e-5;
			lightRay = -lightRay / lightRay.y;

                        //glDepthMask(0);
                        ofPushMatrix();
                        ofMatrix4x4 mat(1,0,0,0, (float)lightRay[0],0,(float)lightRay[2],0, 0,0,1,0, 0,0.01f,0,1);
			ofGetCurrentRenderer()->multMatrix(mat);
			ofSetColor(0,0,0);
                }

                void end(){
                        ofPopMatrix();
			ofPopStyle();
                        //glDepthMask(1);
                }
};
