#include "ofApp.h"

void ofApp::setup() {
    ofEnableLighting();
    ofSetVerticalSync(true);
    ofSetFrameRate(200);
    ofSetBackgroundColor(0, 0, 0);
    ofEnableAlphaBlending();
    ofEnableBlendMode(OF_BLENDMODE_ALPHA);
    ofSetSmoothLighting(true);
    ofSetFullscreen(true);
    ofSetBackgroundAuto(false);
    points[0].nvert = 512;
    lines[0].nvert = 500;
    lines[1].nvert = 250;
    shapes[0].nvert = 1000;
    shapes[1].nvert = 1000;
    mesh[0].nvert = 16;
    mesh[0].init(-numcols/4,-numrows/4,height/4,numcols/4,numrows/4,(height/4)*3);

    for (int i=0;i<1000;i++){
    randi[i].set(ofRandom(-numcols/4,numcols/4),ofRandom(-numrows/4,numrows/4),ofRandom(height/4,(height/4)*3));
    if(i < points[0].nvert) {
        ofVec3f randvel;
        randvel.set(0,0,0);
        points[0].init(i,randi[i].x,randi[i].y,randi[i].z,randvel);
    }
    if(i < numattractors) {
        attractor[i].f = ofRandom(-1,1);
        attractor[i].pos.set(randi[i].x,randi[i].y,randi[i].z);
    if(i == 0){
        attractor[0].f = 1;
        attractor[0].pos.set(0,0,height/2);
      }
    }
  }
    wtarray.sender.setup("localhost", wtarray.port);
    timing.generateSequence();
}

void ofApp::update() {
    timing.playSequence();
    clifford.iterate();
    if (timing.getTrigger()) {
        float x = map.scale(clifford.getX(clifford.getSizeX()-1), 100, 50, true); // clifford attractor value is grabbed from last point of array and scaled
        maxpatch.sendFloat("wavetableFrequency", x); // ...and sent through OSC
    }

    timer += speed;
    space.update();

    //model[0].update();
    //model[0].render(0,0,height*0.5);

    for (int i = 0; i < 1000; ++i) {
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
      if(i<8){
        attractor[i].light.disable();
      }
      if(i<numattractors){
        attractor[i].lighton();
        attractor[i].limit(numcols,numrows,height);
      }
      for(int j=0;j<numattractors;j++){
        if(i<numattractors){
          if(i != j){
            attractor[i].attracted(j,attractor[j].pos,attractor[j].f,numattractors);
            attractor[i].crash(attractor[j].pos);
          }
        }
        if(i<attractor[j].nvert){
          attractor[j].update(i,timer,100,randi[i]);
        }
        if(i<points[0].nvert){
          points[0].attracted(i,attractor[j].pos,attractor[j].f,numattractors);
        }
      }
      if(i<points[0].nvert){
        points[0].update(i,numcols,numrows,height);
        if(i<512){
          wtarray.update(i,numcols,numrows,height,points[0].vertices[i]);
        }
      }
    }
    wtarray.send();
}

void ofApp::draw(){
    bgresetmax = 1;
    bgreset += 1;
    bgreset %= bgresetmax;
    if(bgreset == 0){
        ofBackground(0,0,0);
    }
    space.cam.begin();
    space.drawWireframe(20,250);
    points[0].draw(250,250);

    for (int i=0;i<numattractors;i++){
        attractor[i].draw(10,5);
    }

    //model[0].draw(250,250,timer);
    // mesh[0].draw(250,75);
    // lines[0].draw(250,100);
    // shapes[0].draw(0,2);
    // shapes[1].draw(255,1);
    // lines[1].draw(0,100);

    space.cam.end();
    ofDisableLighting();
    ofSetColor(255);
    ofFill();
    timing.displayData();

}

void ofApp::keyPressed(int key){
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
    for(int i=0;i<numattractors;i++){
      attractor[i].f = ofRandom(-2,2);
    }
  }
  if(key == ' '){
    numattractors += 1;
    numattractors %= 8;
    for(int i=0;i<numattractors;i++){
      attractor[i].f = ofRandom(-2,2);
      attractor[i].pos.set(ofRandom(-numcols/4,numcols/4),ofRandom(-numrows/4,numrows/4),ofRandom(0,height/2));
  }
  }
}

void ofApp::keyReleased(int key){

}

void ofApp::mouseMoved(int x, int y){

}

void ofApp::mouseDragged(int x, int y, int button){

}

void ofApp::mousePressed(int x, int y, int button){

}

void ofApp::mouseReleased(int x, int y, int button){

}

void ofApp::mouseEntered(int x, int y){

}

void ofApp::mouseExited(int x, int y){

}

void ofApp::windowResized(int w, int h){

}

void ofApp::gotMessage(ofMessage msg){

}

void ofApp::dragEvent(ofDragInfo dragInfo){

}
