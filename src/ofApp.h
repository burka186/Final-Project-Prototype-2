#pragma once

#include "ofMain.h"
#include "NoiseObjects.h"


class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    
    //create a class where the class is going to be pulling one of the XML objects and all stuff (size/shape/color associated with it) and will also have functions associated with it
    //part of creating an object is pulling from the XML. do the same thing i currently have in the draw loop to create one new object each time 
    //what direction is it going in? function
    //get bigger while moving in that direction function
    //erase after a certain time function
    
    //in draw loop, iterate over each object that exists and moving it
    //and then creating a new object
    
    //declare ofXml object
    ofXml noise;
    
    //font
    ofTrueTypeFont TTF;
    int fontSize;
    
    //how many noise objects are there in the XML document right now?
    int numNoise;
    
//    //XML iterator
//    int i;
    
    float posX, posY;
    ofColor color;
    
    //vector of noises from XML
    vector <string> noisesXML;
    
    //vector of class NoiseObjects
    vector <NoiseObjects> noiseCollection;
    
    //counter to regulate how fast they draw to the screen
    int timer;
		
};
