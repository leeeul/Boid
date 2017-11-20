#ifndef boid_hpp
#define boid_hpp

#include <stdio.h>
#include "ofMain.h"

class Boid{
public:
    float MAXACC = .1;
    float MAXVEL = 8.;
    
    float tF = 5.5;
    float sF = 4.3;
    float aF = 1.;
    float cF = .6;
    
    ofPoint loc, vel, acc;
    bool captain;
    float radius = 5;
    
    Boid(float x=640, float y=480, bool captain=false);
    
    void update(vector<Boid> *list);
    void draw();
    
    void applyForce(ofPoint vec);
    ofPoint seperate(vector<Boid> *list);
    ofPoint seek(ofPoint vec);
    ofPoint align(vector<Boid> *list);
    ofPoint cohesion(vector<Boid> *list);
};

#endif
