
#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

    ofSetVerticalSync(true);
    vidGrabber.initGrabber(CAM_W, CAM_H);
    bRecording = true;
    
	marker.load("marker.jpg");
	surfTracker.bContrast = true;
	surfTracker.setSize(marker.getWidth(), marker.getHeight());
	surfTracker.detect(marker);
	surfTracker.learnFeatures();

    fps = 0;
    
}



//--------------------------------------------------------------
void ofApp::update() {
    
    if (bRecording){
        vidGrabber.update();
        if(vidGrabber.isFrameNew()) {
            surfTracker.detect(vidGrabber.getPixels().getData(), CAM_W, CAM_H);
			surfTracker.match();
        }
    }
    
    fps += (ofGetFrameRate() - fps)/10;
    
}


//--------------------------------------------------------------
void ofApp::draw() {
	
	ofBackground(255);
    ofSetColor(255);

	ofPushMatrix();
	{
		// mirror camera
		//int w = vidGrabber.getWidth();
		//ofTranslate(w,0);
		//ofScale(-1, 1);

		vidGrabber.draw(0, 0);
		marker.draw(0, 0);

		surfTracker.draw();
	}
	ofPopMatrix();

    
    ofSetColor(0);
    
    ofDrawBitmapString("fps: " + ofToString(fps, 1) +
//                       " - Life: " + ofToString(surfTracker.objectLifeTime, 2) +
                       " - Matches: " + ofToString(surfTracker.getNumGoodMatches())
                       , 10, CAM_H + 20);
    
    ofDrawBitmapString((string)"Keys: " +
                       "\n[p]: pause/play camera " +
                       "\n[f]: toggle features " +
                       "\n[m]: toggle matches " +
                       "\n[r]: toggle responses " +
                       "\n[i]: toggle image "
                       , 10, CAM_H + 50);
    ofDrawBitmapString((string)"Test: "
                       + "\nHold something in front of the camera,"
                       + "\npress SPACE to start learning its features"
                       + "\nPress SPACE again to stop learning"
                       + "\nMove the object around to see the tracking"
                       , 250, CAM_H + 50);
    
    
}

#pragma mark - EVENTS
//--------------------------------------------------------------
void ofApp::keyPressed (int key) {
	switch (key) {
        case 'p':
            bRecording = !bRecording;
            break;
        case 'f':
            surfTracker.bDrawFeatures = !surfTracker.bDrawFeatures;
            break;
        case 'm':
            surfTracker.bDrawMatches = !surfTracker.bDrawMatches;
            break;
        case 'r':
            surfTracker.bDrawResponses = !surfTracker.bDrawResponses;
            break;
        case 'i':
            surfTracker.bDrawImage = !surfTracker.bDrawImage;
            break;
            
	}
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
void ofApp::windowResized(int w, int h){
}

//--------------------------------------------------------------
void ofApp::exit() {
}



