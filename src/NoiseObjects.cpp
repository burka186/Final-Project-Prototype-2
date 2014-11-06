//
//  NoiseObjects.cpp
//  letItOut_2
//
//  Created by Ava Burke on 11/6/14.
//
//

#include "NoiseObjects.h"

//when you create an instance of the class, you pass in its original position (mX, mY)
NoiseObjects::NoiseObjects(float mX, float mY, string mText) {
    //origin position
    //direction
    
    TTF.loadFont("mono.ttf", fontSize);
    
    pos.set(mX, mY);
    vel.x = ofRandom(-1, 1);
    vel.y = ofRandom(-1, 6);
    
    //string (from XML)
    text = mText;
    fontSize = ofRandom(12, 30);
    
    time = ofRandom(60, 600);
    currTime = time;
    
    color = ofRandom(255);
}


void NoiseObjects::update() {
    
    //change position
    //change size
    pos += vel;
    if (pos.x > (ofGetWindowWidth()/6) || pos.x < 0) {
        pos.x = 0;
    }
    if (pos.y > ofGetWindowHeight() || pos.y < 0) {
        pos.y = 0;
    }

    currTime --;
    cout << currTime << endl;
    if(currTime < 0){
        pos.set(ofRandom(ofGetWidth()), ofGetHeight());
        fontSize = ofRandom(8, 44);
        time = ofRandom(60, 2000);
        currTime = time;
        
    }else{
        color = ofMap(currTime, 0, time, 0, 255);
        cout << color << endl;
        
    }
    

    
    //check whether you need to delete it (bool deleteMe) for loop checking all of them and if deleteMe is true, delete it
    
}

void NoiseObjects::render() {
    
    ofSetColor(color);
//    ofRect(pos.x, pos.y, 30, 30);
//
//    //draw to screen
    TTF.drawString(text, pos.x, pos.y);

    
}

