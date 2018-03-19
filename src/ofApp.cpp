#include "ofApp.h"

void ofApp::setup() {
    ofEnableLighting();
    ofSetFrameRate(200);
    ofSetFullscreen(false);
    ofSetVerticalSync(true);
    ofEnableAlphaBlending();
    ofSetSmoothLighting(true);
    ofSetBackgroundAuto(false);
    ofSetBackgroundColor(30, 30, 30);
    ofEnableBlendMode(OF_BLENDMODE_ALPHA);

    light.setup();
    light.setPointLight();
    light.setPosition(0,0,0);
    light.setAttenuation(1,(0.000001/(abs(2))),(0.000001/(abs(2))));

    points[0].init(width,height,depth);
    mesh[0].init(-width/4,-height/4,-depth/4,width/4,height/4,depth/4);
    model[0].init("head.obj",0.75);
    model[1].init("heart.obj",0.75);
    wtarray.sender.setup("localhost", wtarray.port);
}

void ofApp::update() {
    if(timing.getNow()%16 == 0 && ofGetFrameNum()%200 == 0){
      state += 1;
    }
    if(state == 1){
      light.enable();
    }
    if(state == 2){
      light.disable();
      numattractors = 1;
      attractor[0].f = 2;
      attractor[0].pos.set(0,0,0);
    }
    if(state == 3){
      model[1].active = true;
    }

    for (int i=0;i<4;i++){
      attractor[i].light.disable();
    }

    points[0].update(width,height,depth);
    // model[0].render(0,height/4,depth/4,2,5,5);
    model[1].render(0,-height/16,0,2,20,5);
    for(int i=0;i<numattractors;i++){
      attractor[i].limit(width,height,depth);
      attractor[i].lighton();
      attractor[i].update(25);
      points[0].attracted(attractor[i].pos,attractor[i].f,numattractors);
      for(int j=0;j<=numattractors;j++){
        if(j != i){
          attractor[j].attracted(attractor[i].pos,attractor[i].f,numattractors);
        }
      }
    }
    wtarray.update(width, height, depth, points[0].vertices);
    maxpatch.sendFloat("points_vel", points[0].velavrg());
    maxpatch.sendFloat("points_area", points[0].area());
    maxpatch.sendFloat("attractor2_posx", (attractor[1].pos.x));
    maxpatch.sendFloat("attractor3_posx", (attractor[2].pos.x));
    maxpatch.sendFloat("attractor2_posy", (attractor[1].pos.y));
    maxpatch.sendFloat("attractor3_posy", (attractor[2].pos.y));
    maxpatch.sendFloat("attractor2_posz", (attractor[1].pos.z));
    maxpatch.sendFloat("attractor3_posz", (attractor[2].pos.z));
    wtarray.send();
    if(points[0].state == 1) {
      maxpatch.sendBang("pointstate_1");
      points[0].state = 0;
    }
    if(model[0].bang == true){
      maxpatch.sendBang("model0render");
      model[0].bang = false;
    }
    if(model[1].bang == true){
      maxpatch.sendBang("model1render");
      model[1].bang = false;
    }
    if(counter.getX() == 0){
        maxpatch.sendFloat("wtfreq",40);
        counter.setMax(ofRandom(12,24)*100);
    }
    counter.step();

    //debugger stuff
    maxpatch.sendFloat("getNow",timing.getNow());
    maxpatch.sendFloat("state",state);
}

void ofApp::draw(){
    space.cam.begin();
    space.drawBackground(0, 25);
    space.drawWireframe(8, 25);
    points[0].draw(250, 250, 2);
    for (int i=0;i<numattractors;i++){
        attractor[i].draw(10,5);
    }
    // model[0].draw(250,125,180,180,0);
    model[1].draw(250,50,180,180,0.01);
    // mesh[0].draw(250,25);
    space.cam.end();
    timing.displayData();
}

void ofApp::keyPressed(int key){
  // space.movecam(key);
  if(key == '='){
    maxpatch.sendBang("toggledac");
  }
  if(key == '1'){
    space.framedraw = !space.framedraw;
  }
  if(key == '2'){
    for(int i=0;i<4;i++){
      attractor[i].attract = !attractor[i].attract;
    }
  }
  if(key == 'r'){
    points[0].stop();
    for(int i=0;i<numattractors;i++){
      attractor[i].init(height,width,depth);
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
      attractor[i].init(height,width,depth);
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
