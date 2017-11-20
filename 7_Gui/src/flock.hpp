#ifndef flock_hpp
#define flock_hpp

#include <stdio.h>
#include "ofMain.h"
#include "boid.hpp"

class ofApp;

class Flock : public ofBaseApp{
public:
    vector<Boid> list;
    int howMany;
    
    ofApp *app;
    
    Flock(int howMany = 300, int captain = 1);
    
    void init(ofApp *app);
    void update();
    void run();
    
};

#endif /* flock_hpp */
