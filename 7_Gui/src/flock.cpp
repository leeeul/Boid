#include "flock.hpp"
#include "ofApp.h"

Flock::Flock(int howMany, int captain){
    this->howMany = howMany;
    
    for(int i=0; i<howMany; i++){
        list.push_back(
                       Boid( ofRandom(ofGetWidth()/2-50, ofGetWidth()/2+50),
                            ofRandom(ofGetHeight()/2-50, ofGetHeight()/2+50),
                            i<captain?true:false));
    }
}

void Flock::init(ofApp *app){
    this->app=app;
}

void Flock::update(){
    for(int i=0; i<howMany; i++){
        Boid &temp = list.at(i);
        temp.MAXACC = app->acc;
        temp.MAXVEL = app->vel;
        temp.tF = app->target;
        temp.sF = app->seperate;
        temp.aF = app->align;
        temp.cF = app->cohesion;
        temp.update(&list);
    }
}

void Flock::run(){
    for(int i=0; i<howMany; i++){
        list.at(i).draw();
    }
}
