#include "ofApp.h"

void ofApp::setup() {
    ofEnableLighting();
    ofSetFrameRate(200);
    ofSetFullscreen(true);
    ofSetVerticalSync(true);
    ofEnableAlphaBlending();
    ofSetSmoothLighting(true);
    ofSetBackgroundAuto(false);
    ofSetBackgroundColor(30, 30, 30);
    ofEnableBlendMode(OF_BLENDMODE_ALPHA);
    mesh[0].nvert = 16;
    mesh[0].init(-numcols/4,-numrows/4,-height/4,numcols/4,numrows/4,height/4);
    points[0].init(numcols,numrows,height);
    
    for(int i=0;i<numattractors;i++){
      attractor[i].init(numcols,numrows,height);
      attractor[i].f = ofRandom(0,4);
      if(i==0) {
        attractor[0].f = 2;
        attractor[0].pos.set(0,0,0);
      }
    }
    
    wtarray.sender.setup("localhost", wtarray.port);

}

void ofApp::update() {

    for (int i=0;i<4;i++){
      attractor[i].light.disable();
    }
    

    /*
    if (timing.getTrigger() == true) {
        maxpatch.sendBang("note");
    }
     */
    

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
    wtarray.update(numcols, numrows, height, points[0].vertices);
    maxpatch.sendFloat("points_vel", points[0].velavrg());
    maxpatch.sendFloat("points_area", points[0].area());
    maxpatch.sendFloat("bp1_q", (attractor[1].pos.x));
    maxpatch.sendFloat("bp2_q", (attractor[2].pos.x));
    maxpatch.sendFloat("bp1_freq", (attractor[1].pos.y));
    maxpatch.sendFloat("bp2_freq", (attractor[2].pos.y));
    maxpatch.sendFloat("bp1_gain", (attractor[1].pos.z));
    maxpatch.sendFloat("bp2_gain", (attractor[2].pos.z));
    wtarray.send();
    if(points[0].state == 1) {
      maxpatch.sendBang("pointstate_1");
      points[0].state = 0;
    }
    if(counter.getX() == 0){
        maxpatch.sendBang("wtfreqrand");
        counter.setMax(ofRandom(12,24)*100);
    }
    counter.step();
}

void ofApp::draw(){
    space.cam.begin();
    space.drawBackground(0, 20);
    space.drawWireframe(0, 100);
    points[0].draw(250, 250, 2);
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
    
    if (key == 'f') {
        ofToggleFullscreen();
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
