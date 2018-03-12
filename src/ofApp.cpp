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
    ofEnableBlendMode(OF_BLENDMODE_ALPHA);

    mesh[0].nvert = 16;
    mesh[0].init(-numcols/4,-numrows/4,-height/4,numcols/4,numrows/4,height/4);
    points[0].init(numcols,numrows,height);
    for(int i=0;i<numattractors;i++){
      attractor[i].init(numcols,numrows,height);
      attractor[i].f = ofRandom(0,4);
      if(i==0){
        attractor[0].f = 2;
        attractor[0].pos.set(0,0,0);
      }
    }
    wtarray.sender.setup("localhost", wtarray.port);
    timing.generateSequence();
}

void ofApp::update() {
    timing.playSequence();
    clifford.iterate();
    if (timing.getTrigger()) {
        float x = map.scale(clifford.getX(clifford.getSizeX()-1), 100, 50, true);
        maxpatch.sendFloat("wavetableFrequency", x);
    }
    for (int i=0;i<4;i++){
      attractor[i].light.disable();
    }
    model[0].update();
    model[0].render(0,0,height*0.5);
    points[0].update(numcols,numrows,height);
    for(int i;i<numattractors;i++){
      points[0].attracted(attractor[i].pos,attractor[i].f,numattractors);
      attractor[i].lighton();
      attractor[i].limit(numcols,numrows,height);
      attractor[i].update(40);
      // for(int j;j<=numattractors;j++){
      //   if(j != i){
      //     attractor[j].attracted(attractor[i].pos,attractor[i].f,numattractors);
      //   }
      // }
    }

    wtarray.update(numcols,numrows,height,points[0].vertices);
    maxpatch.sendFloat("pointsarea",points[0].area());
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
    space.drawBackground(0,20);
    space.drawWireframe(5,100);
    points[0].draw(250,250,2);
    for (int i=0;i<numattractors;i++){
        attractor[i].draw(10,5);
    }
    // mesh[0].draw(250,25);
    // model[0].draw(250,125);
    space.cam.end();
    timing.displayData();
}

void ofApp::keyPressed(int key){
  space.movecam(key);
  if(key == 'r'){
    points[0].stop();
    for(int i=0;i<numattractors;i++){
      attractor[i].init(numrows,numcols,height);
      if(i == 0){
        attractor[0].pos.set(0,0,0);
      }
      ofBackground(0);
    }
  }
  if(key == ' '){
    numattractors += 1;
    numattractors = numattractors%5;
    points[0].stop();
    for(int i=0;i<numattractors;i++){
      attractor[i].init(numrows,numcols,height);
      if(i == 0){
          attractor[0].pos.set(0,0,0);
        }
      }
      ofBackground(0);
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
