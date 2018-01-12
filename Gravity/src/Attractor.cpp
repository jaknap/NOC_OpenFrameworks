//
//  Attractor.cpp
//  Gravity
//
//  Created by Pankaj Uchil on 26/12/17.
//

#include "Attractor.h"

Attractor::Attractor(){
    
}

//Attractor::Attractor(float posX, float posY){
//    x = posX;
//    y = posY;
//}

void Attractor::setup(){
    //Attractor a1(ofGetWidth()/2,ofGetHeight()/2);
    x= ofGetWidth()/2;
    y= ofGetHeight()/2;
    startPos.set(x,y);
    dim = 20;
    color.set(120,155,0);
}



void Attractor::draw(){
    ofSetColor(color);
    ofDrawCircle(x,y, dim);
}


ofVec2f Attractor::calculateAttraction(ofVec2f position){
    force = startPos - position;
    distance = force.length();
    distance = ofClamp(distance, 5, 20);
    force.normalize();
    strength = (40)/(distance*distance);
    force *= strength;
    return force;
    
    
}
