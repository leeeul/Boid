#ifndef boid_hpp
#define boid_hpp

#include <stdio.h>
#include "ofMain.h"

class Boid{
public:
    const float MAXACC = .4;
    const float MAXVEL = 9.;
    float atField = 13;
    
    ofPoint loc, vel, acc;
    bool captain;
    float radius = 5;
    
    Boid(float x=640, float y=480, bool captain=false);
    
    void update(vector<Boid> *list);
    void draw();
    
    void applyForce(ofPoint vec);
    ofPoint seperate(vector<Boid> *list);
    ofPoint seek(ofPoint vec);
};

#endif
