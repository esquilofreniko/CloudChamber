#include "ofApp.h"

void ofApp::setup() {

  ofSetFullscreen(true);
  ofSetBackgroundAuto(false);
  ofBackground(0,5);

  // ofEnableLighting();
  // ofColor white(255,255,255,255);
  // ofColor red(255,0,0,255);
  // ofColor green(0,255,0,255);
  // ofColor blue(0,0,255,255);
  // ofColor purple(255,0,255,255);
  // light[0].setPointLight();
  // light[0].setDiffuseColor(white);
  // light[0].setPosition(0,0,0);
  // light[0].enable();
  // light[1].setDirectional();
  // light[1].setDiffuseColor(white);
  // light[1].setPosition(0,0,100);
  // light[1].enable();
  // light[2].setPointLight();
  // light[2].setDiffuseColor(white);
  // light[2].setPosition(0,0,50);
  // light[2].enable();
  // light[3].setPointLight();
  // light[3].setDiffuseColor(white);
  // light[3].setPosition(0,0,50);
  // light[3].enable();

  cam.tilt(180);
  cam.setPosition(camx,camy,camz);
  planes[0].set(numcols,numrows);
  planes[0].setPosition(0,0,0);
  planes[0].setResolution(numcols,numrows);
  planes[1].set(numcols,numrows);
  planes[1].setPosition(0,0,height);
  planes[1].setResolution(numcols,numrows);
  planes[2].set(numcols,numrows);
  planes[2].setPosition(0,numrows/2,height/2);
  planes[2].setResolution(numcols,numrows);
  planes[2].rotate(90,1,0,0);
  planes[3].set(numcols,numrows);
  planes[3].setPosition(0,-numrows/2,height/2);
  planes[3].setResolution(numcols,numrows);
  planes[3].rotate(90,1,0,0);
  planes[4].set(numcols,numrows);
  planes[4].setPosition(numcols/2,0,height/2);
  planes[4].setResolution(numcols,numrows);
  planes[4].rotate(90,0,1,0);
  planes[5].set(numcols,numrows);
  planes[5].setPosition(-numcols/2,0,height/2);
  planes[5].setResolution(numcols,numrows);
  planes[5].rotate(90,0,1,0);

  points.nvert = 1;
  lines[0].nvert = 500;
  lines[1].nvert = 250;
  shapes[0].nvert = 1000;
  shapes[1].nvert = 1000;

  mesh.nvert = 16;
  mesh.init(-numcols/4,-numrows/4,height/4,numcols/4,numrows/4,(height/4)*3);

  for (int i=0;i<1000;i++){
    randx[i] = ofRandom(0,1000);
    randy[i] = ofRandom(0,1000);
    randz[i] = ofRandom(0,1000);
  }
    
    masterClock.bpm = 60;
    genA.init(-1.4, 1.6, 1.0, 0.7);
    sineDrone.setup("sine_drone"); // load synthdef

}






void ofApp::update() {
    
    masterClock.update();
    genA.iterate();
    float f = abs(genA.x[masterClock.tick-1] * 200) + 200;
    float a = abs(genA.y[masterClock.tick-1] * 0.5);
    sineDrone.play(f, a);

    timer += speed;
    timerint = abs(timer*100);
    timerint %= 8;
    if(timerint == 0 && otimerint == 1){
        otimerint = 0;
        points.vertices[points.nvert].x = ofRandom(-numcols/2,numcols/2);
        points.vertices[points.nvert].y = ofRandom(-numrows/2,numrows/2);
        points.vertices[points.nvert].z = ofRandom(0,height);
        points.nvert += 1;
        points.nvert %= 1000;
  };
  if(timerint > 0){
    otimerint = 1;
  };
    
  ++counter;
  if (counter >= 64) {
    counter = 0;
  };
    


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

  for (int i=0;i<lines[0].nvert;i++){
    lines[0].vertices[i].x = ofNoise(timer+randx[i])*numcols-(numcols/2);
    lines[0].vertices[i].y = ofNoise(timer+randy[i])*numrows-(numrows/2);
    lines[0].vertices[i].z = ofNoise(timer+randz[i])*height;
  }
  for (int i=0;i<lines[1].nvert;i++){
    lines[1].vertices[i].x = ofNoise(timer+randx[i])*(numcols/4)-(numcols/8);
    lines[1].vertices[i].y = ofNoise(timer+randy[i])*(numrows/4)-(numrows/8);
    lines[1].vertices[i].z = ofNoise(timer+randz[i])*(height/2) + (height/4);
  }
  for (int i=0;i<shapes[0].nvert;i++){
    shapes[0].vertices[i].x = ofNoise(timer+randx[i])*numcols-(numcols/2);
    shapes[0].vertices[i].y = ofNoise(timer+randy[i])*numrows-(numrows/2);
    shapes[0].vertices[i].z = ofNoise(timer+randz[i])*height;
  }
  for (int i=0;i<shapes[1].nvert;i++){
    shapes[1].vertices[i].x = ofNoise(timer+randx[i])*(numcols/4)-(numcols/8);
    shapes[1].vertices[i].y = ofNoise(timer+randy[i])*(numrows/4)-(numrows/8);
    shapes[1].vertices[i].z = ofNoise(timer+randz[i])*(height/2) + (height/4);
  }


    
}

//--------------------------------------------------------------
void ofApp::draw(){
  cam.begin();
  bgresetmax = 1;
  bgreset += 1;
  bgreset %= bgresetmax;
  if(bgreset == 0){
    ofBackground(0,0,0,5);
  }

  ofSetColor(250,10);
  ofFill();
  for (int i=0;i<6;i++){
    planes[i].drawWireframe();
  }

  points.draw(250,200);
  lines[0].draw(250,100);
  shapes[0].draw(0,10);
  shapes[1].draw(200,5);
  lines[1].draw(0,100);

  // mesh.draw(250,75);

  cam.end();
}

//--------------------------------------------------¬------------
void ofApp::keyPressed(int key){
  ofBackground(0,0,0,5);
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
    speed += 0.00001;
  }
  else if(key == '-'){
    speed -= 0.00001;
  }
  if(key == 'n'){
    for (int i=0;i<1000;i++){
      randx[i] = ofRandom(0,1000);
      randy[i] = ofRandom(0,1000);
      randz[i] = ofRandom(0,1000);
    }
  }
  if(key == ' '){
    mesh.init(-numcols/4,-numrows/4,height/4,numcols/4,numrows/4,(height/4)*3);
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
    
    // this code iterates through a generative algorithm, and maps the output to the frequency and amplitude of synth voices
    // intended functionality later on is to improve scaling and mapping to create a more dynamic system in terms of code structure
    // the finished code will not rely upon the mousePressed function, instead relying upon a clock function
    

    //std::cout << "voice: " << sineDrone.currentVoice << " | frequency: " << f << '\n'; // temporary logging
    
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
