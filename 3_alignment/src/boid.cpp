#include "boid.hpp"

Boid::Boid(float x, float y, bool captain){
    loc = ofPoint(x,y);
    vel = ofPoint(0,0);
    acc = ofPoint(0,0);
    this->captain = captain;
    radius = 5;
}

void Boid::update(vector<Boid> *list){
    acc.set(0);
    
    ofPoint toward;
    if(captain){
        toward = seek(ofPoint(ofGetMouseX(), ofGetMouseY()));
    }else{
        toward = seek((*list).at(0).loc);
    }
    applyForce(toward*2.0);
    
    ofPoint sep = seperate(list);
    applyForce(sep*1.9);//1.9
    
    ofPoint ali = align(list);
    applyForce(ali*.3);
    
    ofPoint coh = cohesion(list);
    applyForce(coh*.3);
    
    vel += acc;
    vel.limit(MAXVEL);
    loc += vel;
    loc.x = ofClamp(loc.x, radius, ofGetWidth()-radius);
    loc.y = ofClamp(loc.y, radius, ofGetHeight()-radius);
}

void Boid::draw(){
    if(captain){
        ofSetColor(255,0,0);
    }else{
        ofSetColor(0,100);
    }
    ofDrawCircle(loc, radius);
}

void Boid::applyForce(ofPoint vec){
    acc += vec;
}

ofPoint Boid::seperate(vector<Boid> *list){
    float atField = radius*2.5;
    ofPoint desire(0,0);
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
            temp/=dist; //가까운 녀석일수록 더 멀리 튕기도록 하는 역할
            desire += temp;
            count++;
        }
    }
    
    if(count>0){
        desire /= count;
        desire.normalize();
        desire *= MAXVEL;
    }
    
    desire = desire-vel;
    desire.normalize();
    desire *= MAXACC;
    
    return desire;
}

ofPoint Boid::seek(ofPoint vec){
    ofPoint desire = vec-loc;
    desire.normalize();
    desire *= MAXVEL;
    
    desire = desire-vel;
    desire.normalize();
    desire *= MAXACC;
    
    return desire;
}

ofPoint Boid::align(vector<Boid> *list){
    float boundary = radius*6;
    ofPoint desire(0,0);
    int count = 0;
    
    for(int i=0; i<(*list).size(); i++){
        if(this == &(list->at(i))){
            continue;
        }
        Boid b = list->at(i);
        float dist = loc.distance(b.loc);
        
        if(dist<boundary){
            desire += b.vel;
            count++;
        }
    }
    
    if(count>0){
        desire /= count;
        desire.normalize();
        desire *= MAXVEL;
        
        desire = desire - vel;
        desire.normalize();
        desire *= MAXACC;
    }
    
    return desire;
}

ofPoint Boid::cohesion(vector<Boid> *list){
    float boundary = radius*6;
    ofPoint desire(0,0);
    int count =0;
    
    for(int i=0; i<(*list).size(); i++){
        if(this == &(list->at(i))){
            continue;
        }
        Boid b = list->at(i);
        float dist = loc.distance(b.loc);
        
        if(dist<boundary){
            desire += b.loc;
            count++;
        }
    }
    
    if(count>0){
        desire /= count;
        return seek(desire);
    }else{
        return desire;
    }
}













