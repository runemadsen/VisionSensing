#ifndef _TEST_APP
#define _TEST_APP


#include "ofMain.h"
#include "ofxFBOTexture.h"

class testApp : public ofBaseApp{
	
public:
		
	void setup();
	void update();
	void draw();

	ofImage with;
	ofImage without;
	ofImage output;
	
	unsigned char *	withPixels;
	unsigned char *	withoutPixels;
	unsigned char *	outputPixels;
};

#endif	

