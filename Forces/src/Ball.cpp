#include "Ball.h"
Ball::Ball(){
}

void Ball::setup(){
    x = ofGetWidth()/2;      // give some random positioning
    y = ofGetHeight()/2;
    
    speedX = 0;           // and random speed and direction
    speedY = 0;
    acc.resize(2);
    gravity.resize(2);
    dim = 20;
    
    color.set(0,255,0); // one way of defining digital color is by addressing its 3 components individually (Red, Green, Blue) in a value from 0-255, in this example we're setting each to a random value
}

void Ball::update(){
    
    if(x < 0 ){
        x = 0;
        
        speedX *= -1;
    } else if(x > ofGetWidth()){
        x = ofGetWidth();
        speedX *= -1;
    }
   
    
    if(y < 0 ){
        y = 0;
        speedY = gravity[1];
        speedY *= -1;
        
    } else if(y > ofGetHeight()){
        y = ofGetHeight()/1.5;
        acc[1] *= -1;
        cout<<"ok";
    }
    x+=acc[0];
    y+=acc[1];

    
    }

void Ball::draw(){
    ofSetColor(color);
    ofDrawCircle(x, y, dim);
    
    gravity[0]=0.5;
    gravity[1]= 0.0;
    acc = applyForces(gravity);
    
    
}


vector<float> Ball::applyForces(vector<float>force){
    acc[0] = force[0];
    acc[1] = force[1];
    //cout<<force[1];
    return acc;
    
}
