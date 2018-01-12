#include "Particle.h"
Particle::Particle(){
}

void Particle::setup(){
    x = 400;      // give some random positioning
    y = 150;
    
    speedX = 0;           // and random speed and direction
    speedY = 0;
    acc.resize(2);
    velocity.resize(2);
    gravity.resize(2);
    velocity[0]=1.0;
    velocity[1]=0.0;
    acc[0]=0.0;
    acc[1]=0.0;
    
    dim = 20;
    pos.set(x,y);
    color.set(255,0,0); // one way of defining digital color is by addressing its 3 components individually (Red, Green, Blue) in a value from 0-255, in this example we're setting each to a random value
}

void Particle::update(){

    velocity[0] += acc[0];
    velocity[1] += acc[1];
    x+=velocity[0];
    y+=velocity[1];
    
    acc[0] = 0;
    acc[1] = 0;
    
    
}

void Particle::draw(){
    ofSetColor(color);
    ofDrawCircle(x, y, dim);
    gravity[0] = (myAttractor.calculateAttraction(pos).x);
    gravity[1] = -(myAttractor.calculateAttraction(pos).y);
    acc = applyForces(gravity);
    //gravity[0]=0.5;
    //gravity[1]= 0.0;
   
    
    
}


vector<float> Particle::applyForces(vector<float>force){
    mass = 1;
    acc[0] = force[0];
    acc[1] = force[1];
    force_vec.set(force[0],force[1]);
    
    //cout<<force[1];
    return acc;
    
}
