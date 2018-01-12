//
//  Attractor.hpp
//  Gravity
//
//  Created by Pankaj Uchil on 26/12/17.
//

#ifndef _ATTRACTOR // if this class hasn't been defined, the program can define it
#define _ATTRACTOR // by using this if statement you prevent the class to be called more than once which would confuse the compiler

#include "ofMain.h"

class Attractor{
public:
    void setup();
    void draw();
    void update();
    ofVec2f calculateAttraction(ofVec2f position);
    ofVec2f force;
    
    ofVec2f startPos;
    int G;
    float distance;
    float strength;
    float x;
    float y;
    int dim;
    ofColor color;
    Attractor();
    //Attractor(float posX, float posY);
    
};
#endif
