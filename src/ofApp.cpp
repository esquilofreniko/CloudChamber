#include "ofApp.h"

void ofApp::setup() {
  ofSetFullscreen(true);
  ofSetBackgroundAuto(false);
  ofBackground(0,5);

  space.init(numcols,numrows,height);

  points[0].nvert = 512;
  lines[0].nvert = 500;
  lines[1].nvert = 250;
  shapes[0].nvert = 1000;
  shapes[1].nvert = 1000;
  mesh[0].nvert = 16;

  mesh[0].init(-numcols/4,-numrows/4,height/4,numcols/4,numrows/4,(height/4)*3);

  for (int i=0;i<1000;i++){
    randx[i] = ofRandom(0,1000);
    randy[i] = ofRandom(0,1000);
    randz[i] = ofRandom(0,1000);
  }

    genA.init(-1.4, 1.6, 1.0, 0.7);
    sineDrone.setup("sine_drone"); // load synthdef

}

void ofApp::update() {

  ++counter;
  if (counter >= 128) {
      counter = 0;
  };

  timer += speed;

  // masterClock.update();
  genA.iterate();
  if (counter % 16 == 1) {
      float f = abs(genA.x[counter-1] * 300) + 100;
      float a = abs(genA.y[counter-1] * 0.5);
      sineDrone.play(f, a);
  }

  space.update();

  //update shape positions
  for (int i=0;i<1000;i++){
    if(i<lines[0].nvert){
      lines[0].vertices[i].x = ofNoise(timer+randx[i])*numcols-(numcols/2);
      lines[0].vertices[i].y = ofNoise(timer+randy[i])*numrows-(numrows/2);
      lines[0].vertices[i].z = ofNoise(timer+randz[i])*height;
    }
    if(i<lines[1].nvert){
      lines[1].vertices[i].x = ofNoise(timer+randx[i])*(numcols/4)-(numcols/8);
      lines[1].vertices[i].y = ofNoise(timer+randy[i])*(numrows/4)-(numrows/8);
      lines[1].vertices[i].z = ofNoise(timer+randz[i])*(height/2) + (height/4);
    }
    if(i<shapes[0].nvert){
      shapes[0].vertices[i].x = ofNoise(timer+randx[i])*numcols-(numcols/2);
      shapes[0].vertices[i].y = ofNoise(timer+randy[i])*numrows-(numrows/2);
      shapes[0].vertices[i].z = ofNoise(timer+randz[i])*height;
    }
    if(i<shapes[1].nvert){
      shapes[1].vertices[i].x = ofNoise(timer+randx[i])*(numcols/4)-(numcols/8);
      shapes[1].vertices[i].y = ofNoise(timer+randy[i])*(numrows/4)-(numrows/8);
      shapes[1].vertices[i].z = ofNoise(timer+randz[i])*(height/2) + (height/4);
    }
    if(i<points[0].nvert){
      points[0].vertices[i].x = ofNoise(timer+randx[i])*numcols-(numcols/2);
      points[0].vertices[i].y = ofNoise(timer+randy[i])*numrows-(numrows/2);
      points[0].vertices[i].z = ofNoise(timer+randz[i])*height;
    }
  }
}


//--------------------------------------------------------------
void ofApp::draw(){
  space.cam.begin();
  bgresetmax = 1;
  bgreset += 1;
  bgreset %= bgresetmax;
  if(bgreset == 0){
    ofBackground(0,0,0,5);
  }

  ofSetColor(250,10);
  ofFill();
  for (int i=0;i<6;i++){
    space.planes[i].drawWireframe();
  }

  points[0].draw(255,255);

  // lines[0].draw(250,100);
  // shapes[0].draw(0,10);
  // shapes[1].draw(200,5);
  // lines[1].draw(0,100);

  // mesh[0].draw(250,75);

  space.cam.end();
}

//--------------------------------------------------¬------------
void ofApp::keyPressed(int key){
  ofBackground(0,0,0,5);
  if(key == 'w'){
    space.cam.dolly(-1);
  }
  else if(key == 's'){
    space.cam.dolly(1);
  }
  if(key == 'a'){
    space.cam.pan(4);
  }
  else if(key == 'd'){
    space.cam.pan(-4);
  }
  if(key == 'e'){
    space.cam.tilt(1);
  }
  else if(key == 'q'){
    space.cam.tilt(-1);
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
    mesh[0].init(-numcols/4,-numrows/4,height/4,numcols/4,numrows/4,(height/4)*3);
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
