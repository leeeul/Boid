#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetWindowShape(960, 250);
    ofBackground(255);
    ofSetBackgroundAuto(false);
    
    f1 = Flock(350,10);
    f1.init(this);
    
    gui.setup();
    gui.add(acc.setup("acc",.1,0.01,1.));
    gui.add(vel.setup("vel",8.,1.,15.));
    gui.add(target.setup("targeting",5.5,1.,10.));
    gui.add(seperate.setup("seperation",4.3,1.,10.));
    gui.add(align.setup("alignment",1.,0.,5.));
    gui.add(cohesion.setup("cohesion",.6,0.,5.));
}

//--------------------------------------------------------------
void ofApp::update(){
    f1.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetColor(0, 5);//10
    ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());
    
    f1.run();
    gui.draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
    
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){
    
}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){
    
}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){
    
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){
    
}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){
    
}
