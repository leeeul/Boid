#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetWindowShape(640, 480);
    ofBackground(255);
    
    for(int i=0; i<howMany ; i++){
        list.push_back( Boid( ofRandom(ofGetWidth()/2-50, ofGetWidth()/2+50),
                             ofRandom(ofGetHeight()/2-50, ofGetHeight()/2+50))   );
    }
}

//--------------------------------------------------------------
void ofApp::update(){
    for(int i=0; i<howMany; i++){
        list.at(i).update(&list);
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    for(int i=0; i<howMany; i++){
        list.at(i).draw();
    }
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
