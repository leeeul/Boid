#include "boid.hpp"

Boid::Boid(float x, float y){
    loc = ofPoint(x,y);
    vel = ofPoint(0,0);
    acc = ofPoint(0,0);
    radius = 5;
}

void Boid::update(vector<Boid> *list){
    acc.set(0);
    
    ofPoint desireVel = seperate(list)-vel;
    desireVel.normalize();
    desireVel *= MAXACC;
    applyForce(desireVel);
    
    vel += acc;
    loc += vel;
    loc.x = ofClamp(loc.x, radius, ofGetWidth()-radius);
    loc.y = ofClamp(loc.y, radius, ofGetHeight()-radius);
}

void Boid::draw(){
    ofSetColor(0,100);
    ofDrawCircle(loc, radius);
}

void Boid::applyForce(ofPoint vec){
    acc += vec;
}

ofPoint Boid::seperate(vector<Boid> *list){
    ofPoint forSaving(0,0);
    int count=0;
    
    for(int i=0; i<(*list).size(); i++){
        if(this == &((*list).at(i))){
            continue;
        }
        
        ofPoint otherLoc = (*list).at(i).loc;
        float dist = loc.distance(otherLoc);
        
        if(dist<atField){
            ofPoint temp = loc-otherLoc;
            temp.normalize();
            forSaving += temp;
            count++;
        }
    }
    
    if(count>0){
        forSaving /= count;
        forSaving.normalize();
        forSaving *= MAXVEL;
    }
    
    return forSaving;
    
}


