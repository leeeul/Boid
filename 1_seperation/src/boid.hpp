#ifndef boid_hpp
#define boid_hpp

#include <stdio.h>
#include "ofMain.h"

class Boid{
public:
    const float MAXACC = .3;
    const float MAXVEL = 2.;
    float atField = 20;
    
    ofPoint loc, vel, acc;
    float radius = 5;
    
    Boid(float x=640, float y=480);
    
    void update(vector<Boid> *list);
    void draw();
    
    void applyForce(ofPoint vec);
    ofPoint seperate(vector<Boid> *list);
};

#endif
