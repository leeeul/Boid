#include "flock.hpp"

Flock::Flock(int howMany){
    this->howMany = howMany;
    
    for(int i=0; i<howMany; i++){
        list.push_back(Boid( ofRandom(ofGetWidth()/2-50, ofGetWidth()/2+50),
                            ofRandom(ofGetHeight()/2-50, ofGetHeight()/2+50),
                            i==0?true:false));
    }
}

void Flock::update(){
    for(int i=0; i<howMany; i++){
        list.at(i).update(&list);
    }
}

void Flock::run(){
    for(int i=0; i<howMany; i++){
        list.at(i).draw();
    }
}
