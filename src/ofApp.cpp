#include "ofApp.h"

void ofApp::setup() {
  ofSetFullscreen(false);
  ofSetBackgroundAuto(false);
  ofBackground(0,0,0);

  space.init(numcols,numrows,height);

  points[0].nvert = 512;
  lines[0].nvert = 500;
  lines[1].nvert = 250;
  shapes[0].nvert = 1000;
  shapes[1].nvert = 1000;
  mesh[0].nvert = 16;

  mesh[0].init(-numcols/4,-numrows/4,height/4,numcols/4,numrows/4,(height/4)*3);

  for (int i=0;i<1000;i++){
    randi[i].set(ofRandom(-numcols/4,numcols/4),ofRandom(-numrows/4,numrows/4),ofRandom(height/4,(height/4)*3));
    if(i<points[0].nvert){
      ofVec3f randvel;
      randvel.set(0,0,0);
      points[0].init(i,randi[i].x,randi[i].y,randi[i].z,randvel);
    }
    if(i<numattractors){
      attractor[i].f = ofRandom(-1,1);
      attractor[i].pos.set(randi[i].x,randi[i].y,randi[i].z);
      if(i==0){
        attractor[0].f = 1;
        attractor[0].pos.set(0,0,height/2);
      }
    }
  }

    genA.init(-1.4, 1.6, 1.0, 0.7);
    sender.setup("localhost", port);
}

void ofApp::update() {
  space.update();

  if (counter >= 128) {
    counter = 0;
  };
  ofxOscMessage wtx [4];
  ofxOscMessage wty [4];
  ofxOscMessage wtz [4];
  ofxOscMessage wtreset;
  wtreset.setAddress("wtreset");
  sender.sendMessage(wtreset);

  timer += speed;

  // masterClock.update();
  genA.iterate();
  if (counter % 16 == 1) {
      float f = abs(genA.x[counter-1] * 300) + 100;
      float a = abs(genA.y[counter-1] * 0.5);
  }

  //update shape positions
  for (int i=0;i<1000;i++){
    if(i<4){
      wtx[i].setAddress("wtx" + std::to_string(i));
      wty[i].setAddress("wty" + std::to_string(i));
      wtz[i].setAddress("wtz" + std::to_string(i));
    }
    if(i<lines[0].nvert){
      lines[0].vertices[i].set(ofNoise(timer+randi[i].x)*numcols-(numcols/2),ofNoise(timer+randi[i].y)*numrows-(numrows/2),ofNoise(timer+randi[i].z)*height);
    }
    if(i<lines[1].nvert){
      lines[1].vertices[i].set(ofNoise(timer+randi[i].x)*(numcols/4)-(numcols/8),ofNoise(timer+randi[i].y)*(numrows/4)-(numrows/8),ofNoise(timer+randi[i].z)*(height/2) + (height/4));
    }
    if(i<shapes[0].nvert){
      shapes[0].vertices[i].set(ofNoise(timer+randi[i].x)*numcols-(numcols/2),ofNoise(timer+randi[i].y)*numrows-(numrows/2),ofNoise(timer+randi[i].z)*height);
    }
    if(i<shapes[1].nvert){
      shapes[1].vertices[i].set(ofNoise(timer+randi[i].x)*(numcols/4)-(numcols/8),ofNoise(timer+randi[i].y)*(numrows/4)-(numrows/8),ofNoise(timer+randi[i].z)*(height/2) + (height/4));
    }
    for(int j=0;j<numattractors;j++){
      if(i<attractor[j].nvert){
        attractor[j].update(i);
      }
      if(i<points[0].nvert){
        points[0].attracted(i,attractor[j].pos,attractor[j].f,numattractors);
      }
    }
    if(i<points[0].nvert){
      points[0].update(i,numcols,numrows,height);
      if(i<128){
        wta[0][i].x = abs((points[0].vertices[i].x)/(numrows/2))*0.95;
        wta[0][i].y = abs((points[0].vertices[i].y)/(numcols/2))*0.95;
        wta[0][i].z = abs((points[0].vertices[i].z)/(height))*0.95;
        wtx[0].addFloatArg(wta[0][i].x);
        wty[0].addFloatArg(wta[0][i].y);
        wtz[0].addFloatArg(wta[0][i].z);
      }
      if(i<256){
        wta[1][i-128].x = abs((points[0].vertices[i].x)/(numrows/2))*0.95;
        wta[1][i-128].y = abs((points[0].vertices[i].y)/(numcols/2))*0.95;
        wta[1][i-128].z = abs((points[0].vertices[i].z)/(height))*0.95;
        wtx[1].addFloatArg(wta[1][i-128].x);
        wty[1].addFloatArg(wta[1][i-128].y);
        wtz[1].addFloatArg(wta[1][i-128].z);
      }
      if(i<384){
        wta[2][i-256].x = (abs((points[0].vertices[i].x)/(numrows/2))*0.95)*-1;
        wta[2][i-256].y = (abs((points[0].vertices[i].y)/(numcols/2))*0.95)*-1;
        wta[2][i-256].z = (abs((points[0].vertices[i].z)/(height))*0.95)*-1;
        wtx[2].addFloatArg(wta[2][i-256].x);
        wty[2].addFloatArg(wta[2][i-256].y);
        wtz[2].addFloatArg(wta[2][i-256].z);
      }
      if(i<512){
        wta[3][i-384].x = (abs((points[0].vertices[i].x)/(numrows/2))*0.95)*-1;
        wta[3][i-384].y = (abs((points[0].vertices[i].y)/(numcols/2))*0.95)*-1;
        wta[3][i-384].z = (abs((points[0].vertices[i].z)/(height))*0.95)*-1;
        wtx[3].addFloatArg(wta[3][i-384].x);
        wty[3].addFloatArg(wta[3][i-384].y);
        wtz[3].addFloatArg(wta[3][i-384].z);
      }
    }
  }
  if(counter == 0){
    for(int i=0;i<4;i++){
      sender.sendMessage(wtx[i]);
      sender.sendMessage(wty[i]);
      sender.sendMessage(wtz[i]);
    }
  }
  ++counter;
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

  ofSetColor(25,50);
  ofFill();
  for (int i=0;i<6;i++){
    space.planes[i].drawWireframe();
  }

  for (int i=0;i<numattractors;i++){
    if(attractor[i].f==0){
      attractor[i].draw(0,0,0,attractor[i].f*20);
    }
    if(attractor[i].f>0){
      attractor[i].draw(100,0,175,(attractor[i].f*20)+5);
    }
    if(attractor[i].f<0){
      attractor[i].draw(200,0,0,((attractor[i].f*-1)*20)+5);
    }
  }

  points[0].draw(255,255);

  // mesh[0].draw(250,75);

  // lines[0].draw(250,100);
  shapes[0].draw(0,5);
  shapes[1].draw(200,2);
  // lines[1].draw(0,100);

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
      randi[i].set(ofRandom(0,1000),ofRandom(0,1000),ofRandom(0,1000));
    }
  }
  if(key == ' '){
    for(int i=0;i<numattractors;i++){
      attractor[i].f = ofRandom(-1,1);
      attractor[i].pos.set(ofRandom(-numcols/4,numcols/4),ofRandom(-numrows/4,numrows/4),(height/4,(height/4)*3));
    }
    // mesh[0].init(-numcols/4,-numrows/4,height/4,numcols/4,numrows/4,(height/4)*3);
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
