#include "boid.hpp"

Boid::Boid(float x, float y, bool captain){
    loc = ofPoint(x,y);
    vel = ofPoint(0,0);
    acc = ofPoint(0,0);
    this->captain = captain;
}

void Boid::update(vector<Boid> *list){
    acc.set(0);
    
    ofPoint toward;
    if(captain){
        toward = seek(ofPoint(ofGetMouseX(), ofGetMouseY()));
    }else{
        float dist = 100000;
        int index;
        for(int i=0; i<(*list).size(); i++){
            if(list->at(i).captain){
                float tDist = loc.distance(list->at(i).loc);
                if(tDist<dist){
                    dist = tDist;
                    index = i;
                }
            }else{
                break;
            }
        }
        toward = seek((*list).at(index).loc);
    }
    applyForce(toward*tF);
    
    ofPoint sep = seperate(list);
    applyForce(sep*sF);
    
    ofPoint ali = align(list);
    applyForce(ali*aF);
    
    ofPoint coh = cohesion(list);
    applyForce(coh*cF);
    
    vel += acc;
    vel.limit(MAXVEL);
    loc += vel;
    
    loc.x = loc.x>=ofGetWidth() ? loc.x-ofGetWidth() : loc.x;
    loc.x = loc.x<=0 ?loc.x+ofGetWidth() : loc.x;
    
    loc.y = loc.y>=ofGetHeight() ? loc.y-ofGetHeight() : loc.y;
    loc.y = loc.y<=0 ? loc.y+ofGetHeight() : loc.y;
    //    loc.x = ofClamp(loc.x, radius, ofGetWidth()-radius);
    //    loc.y = ofClamp(loc.y, radius, ofGetHeight()-radius);
}

void Boid::draw(){
    if(captain){
        ofSetColor(255,0,0,70);
    }else{
        ofSetColor(255,50);
    }
    float degree = vel.angle(ofPoint(1,0));
    if(vel.y<0){
        degree *= -1;
    }
//    cout<<vel<<endl;
    
    ofPushMatrix();
    
    ofTranslate(loc);
    ofRotate(degree);
    ofDrawTriangle(0,radius, 2.5*radius,0,0,-radius);
    
    ofPopMatrix();
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













