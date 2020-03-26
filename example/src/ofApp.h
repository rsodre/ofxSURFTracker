#pragma once

#include "ofMain.h"

// SURF Trackers
#include "ofxSURFTracker.h"

// CAMERA
#define CAM_W 640
#define CAM_H 480

class ofApp : public ofBaseApp {
public:
	
	void setup();
	void update();
	void draw();
	void exit();
	
	void keyPressed(int key);
	void mouseDragged(int x, int y, int button);
	void mousePressed(int x, int y, int button);
	void mouseReleased(int x, int y, int button);
	void windowResized(int w, int h);

    float fps;
	bool bRecording;

    ofVideoGrabber vidGrabber;
	ofImage marker;
    
    // SURF
    ofxSURFTracker surfTracker;
};
