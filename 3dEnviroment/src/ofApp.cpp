#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
  ofEnableDepthTest();
  ofBackground(0);
  cam.tilt(90);
  cam.setPosition(camx,camy,camz);
  plane1.set(numcols,numrows);
  plane1.setPosition(0,0,0);
  plane1.setResolution(numcols,numrows);
}

//--------------------------------------------------------------
void ofApp::update(){
}

//--------------------------------------------------------------
void ofApp::draw(){
  cam.begin();
  plane1.drawWireframe();
  cam.end();
}

//--------------------------------------------------¬------------
void ofApp::keyPressed(int key){
  if(key == 'w'){
    cam.dolly(-1);
  }
  else if(key == 's'){
    cam.dolly(1);
  }
  if(key == 'a'){
    cam.pan(4);
  }
  else if(key == 'd'){
    cam.pan(-4);
  }
  if(key == 'e'){
    // cam.tilt(1);
  }
  else if(key == 'q'){
    // cam.tilt(-1);
  }
  campos = cam.getPosition();
  if(campos.x<-numcols/2){
    cam.setPosition(-numcols/2,campos.y,campos.z);
  }
  if (campos.x>numcols/2){
    cam.setPosition(numcols/2,campos.y,campos.z);
  }
  if(campos.y<-numrows/2){
    cam.setPosition(campos.x,-numrows/2,campos.z);
  }
  if (campos.y>numrows/2){
    cam.setPosition(campos.y,numrows/2,campos.z);
  }
  if(key == 'w' || key == 's'){
    std::cout << campos.x << endl;
    std::cout << campos.y << endl;
  }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y){

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
