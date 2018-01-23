#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
  ofSetFullscreen(true);
  ofSetBackgroundAuto(false);
  ofBackground(0,5);
  cam.tilt(180);
  cam.setPosition(camx,camy,camz);
  plane1.set(numcols,numrows);
  plane1.setPosition(0,0,0);
  plane1.setResolution(numcols,numrows);
  plane2.set(numcols,numrows);
  plane2.setPosition(0,0,height);
  plane2.setResolution(numcols,numrows);
  plane3.set(numcols,numrows);
  plane3.setPosition(0,numrows/2,height/2);
  plane3.setResolution(numcols,numrows);
  plane3.rotate(90,1,0,0);
  plane4.set(numcols,numrows);
  plane4.setPosition(0,-numrows/2,height/2);
  plane4.setResolution(numcols,numrows);
  plane4.rotate(90,1,0,0);
  plane5.set(numcols,numrows);
  plane5.setPosition(numcols/2,0,height/2);
  plane5.setResolution(numcols,numrows);
  plane5.rotate(90,0,1,0);
  plane6.set(numcols,numrows);
  plane6.setPosition(-numcols/2,0,height/2);
  plane6.setResolution(numcols,numrows);
  plane6.rotate(90,0,1,0);
}

//--------------------------------------------------------------
void ofApp::update(){
  timer += ballspeed;
  campos = cam.getPosition();
  if(campos.x<(-numcols/2)+10){
    cam.setPosition((-numcols/2)+10,campos.y,campos.z);
  }
  if (campos.x>(numcols/2)-10){
    cam.setPosition((numcols/2)-10,campos.y,campos.z);
  }
  if(campos.y<(-numrows/2)+10){
    cam.setPosition(campos.x,(-numrows/2)+10,campos.z);
  }
  if (campos.y>(numrows/2)-10){
    cam.setPosition(campos.x,(numrows/2)-10,campos.z);
  }
  if (campos.z<0+10){
    cam.setPosition(campos.x,campos.y,0+10);
  }
  if(campos.z>height-10){
    cam.setPosition(campos.x,campos.y,height-10);
  }
}

//--------------------------------------------------------------
void ofApp::draw(){
  cam.begin();
  ofBackground(0,0,0,5);
  ofSetColor(25);
  ofFill();
  plane1.drawWireframe();
  plane2.drawWireframe();
  plane3.drawWireframe();
  plane4.drawWireframe();
  plane5.drawWireframe();
  plane6.drawWireframe();

  for (int i=0;i<100;i++){
    balls[i].draw(((ofNoise(timer+(i*balls[i].randx))*100)-50),((ofNoise(timer+(i*balls[i].randy))*100)-50),((ofNoise(timer+(i*balls[i].randz))*100)));
    ofDrawLine(balls[i].pos.x,balls[i].pos.y,balls[i].pos.z,balls[(i+1)%101].pos.x,balls[(i+1)%101].pos.y,balls[(i+1)%101].pos.z);
  }
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
    cam.tilt(1);
  }
  else if(key == 'q'){
    cam.tilt(-1);
  }
  if(key == '+'){
    ballspeed += 0.00001;
  }
  else if(key == '-'){
    ballspeed -= 0.00001;
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
