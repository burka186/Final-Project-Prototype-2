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

    //define j = 0 to start off with
    int j = 0;
    
    //populate vector with existing data from XML file until you reach desired number of objects
    for (int i = 0; i < 207; i++) {
        
       
        //point to current noise_objects/noise[j] with j starting at 0
        noise.setToChild(i);
        //get value at index number j
        string s = noise.getValue();
        cout << s << endl;
        
        //make a new NoiseObjects instance
        NoiseObjects newNoise(ofRandom(0, ofGetWindowWidth()), ofRandom(0, ofGetWindowHeight()), s);
        //push back to noiseCollection vector
        noiseCollection.push_back(newNoise);
        
        j++;
        
        //x represents whether the current i we're on is a multiple of numnoise (the % is a modulo operator)
            int x = i % numNoise;
            //cout << x << endl;
            //if it is a multiple (i.e. no remainder), then reset j to 0
            if (x == 0) {
                j = 0;
                noise.setToSibling();
            }
        
        
        
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
