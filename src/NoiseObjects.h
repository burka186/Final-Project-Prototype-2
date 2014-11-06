//
//  NoiseObjects.h
//  letItOut_2
//
//  Created by Ava Burke on 11/6/14.
//
//

#pragma once
#include "ofMain.h"

class NoiseObjects {
    //when you create the object (an instance of the class) for the first time, you feed it information about what you're doing
public:
    NoiseObjects (
        float mX,
        float mY,
        //string being passed into the constructor
        string mText
    );
    
    
        void update();
        void render();
    
    //text that's getting drawn to the screen
    string text;
    
    ofColor color;
    ofTrueTypeFont TTF;
    int fontSize;
    
    //timer stuff
    int currTime;
    int time;

    
    ofVec2f pos;
    ofVec2f vel;
};
