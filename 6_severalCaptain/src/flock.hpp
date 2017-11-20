#ifndef flock_hpp
#define flock_hpp

#include <stdio.h>
#include "ofMain.h"
#include "boid.hpp"

class Flock{
public:
    vector<Boid> list;
    int howMany;
    
    Flock(int howMany = 300, int captain = 1);
    
    void update();
    void run();
};

#endif /* flock_hpp */
