#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetFrameRate(60);

    //ofSetBackgroundAuto(false);
    ofBackground(0, 0, 0, 100);
    ofDisableAntiAliasing();
    ofSetVerticalSync(true);
    ofEnableAlphaBlending();
    
    //load XML file
    noise.load("rage_noise.xml");
    
    //point to parent node
    noise.setTo("noise_objects");

    //set color
    color = (255);

    //how many objects are there in the XML file right now?
    numNoise = noise.getNumChildren();
    
    cout << numNoise << endl;
    
//    posX = ofRandom((ofGetWindowWidth()/6)*-1, 0);
//    posY = ;
    
    //populate vector with existing data from XML file
    for (int i = 0; i < numNoise; i++) {
        //point to current noise_objects/noise[i]
        noise.setToChild(i);
        string s = noise.getValue();
        //set XML file pointer to next sibling node
        noise.setToSibling();
        //make a new NoiseObjects instance
        NoiseObjects newNoise(0, ofRandom(0, ofGetWindowHeight()), s);
        //push back to noiseCollection vector
        noiseCollection.push_back(newNoise);
    }
    
    
}

//--------------------------------------------------------------
void ofApp::update(){

    //call the NoiseObjects update() function for however many objects are in the noiseCollection vector at thist time
    for (int i = 0; i < noiseCollection.size(); i++) {
        noiseCollection[i].update();
    }   

}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(0);
    
    
    //draw current object in noiseCollection vector to screen
    for (int i = 0; i < noiseCollection.size(); i++) {
        noiseCollection[i].render();
    }
    

    
//    if (i < (noisesXML.size()-1)) {
//        i++;
//    } else i = 0;
    
  
    //draw the phrases onto the screen
//    for (int i = 0; i < noises.size(); i++){
//        string currentNoise = noises[i];
//        TTF.drawString(currentNoise, ofRandom(-100, ofGetWindowWidth()/2), ofRandom(0, ofGetWindowHeight()));
//    }
    
    
  
    
//    for (int i = 0; i < numNoise; i++) {
//        noise.setToChild(i);
//        cout << noise.setToChild(i) << endl;
//    }
    
//    cout << noise.getValue("noise[0]/string") << endl;
    
    
//    for(int i = 0; i < (numNoise - 1); i++) {
//        noise.setTo("noise_objects/noise[@id=0]");
//        ofDrawBitmapString(noise.getValue("noise_objects/noise[@id=i]/string"), posX, posY);
//        cout << noise.getValue("noise_objects/noise[@id=i]/string") << endl;
//    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
