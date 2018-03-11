#include "ofApp.h"

void ofApp::setup() {
    ofEnableLighting();
    ofSetFrameRate(200);
    ofSetFullscreen(false);
    ofSetVerticalSync(true);
    ofEnableAlphaBlending();
    ofSetSmoothLighting(true);
    ofSetBackgroundAuto(false);
    ofSetBackgroundColor(0, 0, 0);
    // ofEnableBlendMode(OF_BLENDMODE_ALPHA);

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
        attractor[i].f = ofRandom(-4,4);
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

    space.update();
    model[0].update();
    model[0].render(0,0,height*0.5);
    for(int i;i<numattractors;i++){
      attractor[i].light.disable();
      attractor[i].lighton();
      attractor[i].limit(numcols,numrows,height);
      attractor[i].update(25);
      points[0].update(numcols,numrows,height);
      points[0].attracted(attractor[i].pos,attractor[i].f,numattractors);
      for(int j;j<numattractors;j++){
        if(i != 0 && i != j){
          attractor[i].attracted(j,attractor[j].pos,attractor[j].f,numattractors);
        }
      }
    }

    wtarray.update(numcols,numrows,height,points[0].vertices);
    maxpatch.sendFloat("bp1q",(attractor[1].pos.x));
    maxpatch.sendFloat("bp2q",(attractor[2].pos.x));
    maxpatch.sendFloat("bp1freq",(attractor[1].pos.y));
    maxpatch.sendFloat("bp2freq",(attractor[2].pos.y));
    maxpatch.sendFloat("bp1gain",(attractor[1].pos.z));
    maxpatch.sendFloat("bp2gain",(attractor[2].pos.z));
    wtarray.send();
    if(fcounter == 0){
      maxpatch.sendBang("wtfreqrand");
      fcountermax = ofRandom(12,24)*100;
    }
    fcounter += 1;
    fcounter %=fcountermax;
}

void ofApp::draw(){
    space.cam.begin();
    space.drawWireframe(10,125);
    space.drawBackground(0,20);
    points[0].draw(255,125,1);
    for (int i=0;i<numattractors;i++){
        attractor[i].draw(10,5);
    }
    model[0].draw(250,100);
    // mesh[0].draw(250,75);

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
  if(key == 'r'){
    for(int i=0;i<numattractors;i++){
      attractor[i].vel = ofVec3f(0,0,0);
      attractor[i].f = ofRandom(-2,2);
      attractor[i].pos.set(ofRandom(-numcols/4,numcols/4),ofRandom(-numrows/4,numrows/4),ofRandom(0,height/2));
      if(i == 0){
          attractor[0].pos.set(0,0,height/2);
        }
      space.drawBackground(0,255);
    }
  }
  if(key == 'n'){
    for(int i=0;i<numattractors;i++){
      attractor[i].vel = ofVec3f(0,0,0);
      attractor[i].f = ofRandom(-2,2);
    }
  }
  if(key == ' '){
    numattractors += 1;
    numattractors %= 5;
    for(int i=0;i<numattractors;i++){
      attractor[i].vel = ofVec3f(0,0,0);
      attractor[i].f = ofRandom(-2,2);
      attractor[i].pos.set(ofRandom(-numcols/4,numcols/4),ofRandom(-numrows/4,numrows/4),ofRandom(0,height/2));
      if(i == 0){
          attractor[0].pos.set(0,0,height/2);
        }
      }
      space.drawBackground(0,255);
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
