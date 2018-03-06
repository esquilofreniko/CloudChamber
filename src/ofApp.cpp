#include "ofApp.h"

void ofApp::setup() {
    ofBackground(20, 20, 20);
    ofSetFrameRate(200);
    ofSetFullscreen(true);
    ofSetBackgroundAuto(false);
    ofEnableLighting();
    ofEnableBlendMode(OF_BLENDMODE_ALPHA);
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
    // example of using clifford attractor object and sending its output via osc
    // will later encapsulate this code elsewhere...
    
    
    std::string addresses[16];

    for (int i = 0; i < 128; ++i) {
        clifford.iterate();
    }
    
    for (int i = 0; i < 16; ++i) {
        if (i == 0) maxpatch.sendBang("trigger");
        addresses[i] = 'f'+(std::to_string(i+1)); // to_string converts integer to string data type
        float x = map.scale(clifford.getX(i), 100, 50, true);
        std::cout << x << '\n';
        maxpatch.sendFloat(addresses[i], x);
    }
    
        wtarray.sender.setup("localhost", wtarray.port);
}

void ofApp::update() {
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
    for(int j=0;j<numattractors;j++){
      if(i<attractor[j].nvert){
        attractor[j].update(i,timer,randi[i]);
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

//--------------------------------------------------------------
void ofApp::draw(){
    ofEnableLighting();
    space.cam.begin();
    bgresetmax = 1;
    bgreset += 1;
    bgreset %= bgresetmax;
    if(bgreset == 0){
        ofBackground(0,0,0,5);
    }
    ofSetColor(50, 100);
    ofFill();
    space.drawWireframe();
    points[0].draw(250,250);
    for (int i=0;i<numattractors;i++){
        attractor[i].draw(0,10,250,6);
    }
  //model[0].draw(250,250,timer);
  // mesh[0].draw(250,75);

  // lines[0].draw(250,100);
  // shapes[0].draw(0,2);
  // shapes[1].draw(255,1);
  // lines[1].draw(0,100);
    attractor[0].draw(0,10,250,6);
    space.cam.end();
    ofDisableLighting();
    ofSetColor(255);
    ofFill();
    ofDrawBitmapString("fps: "+ofToString(ofGetFrameRate(), 2), 10, 15);
}

//--------------------------------------------------¬------------
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
    for (int i=0;i<1000;i++){
      randi[i].set(ofRandom(0,1000),ofRandom(0,1000),ofRandom(0,1000));
    }
  }
  if(key == ' '){
    numattractors = ofRandom(2,2);
    for(int i=0;i<numattractors;i++){
      attractor[i].f = ofRandom(0,1);
      attractor[i].pos.set(ofRandom(-numcols/2,numcols/2),ofRandom(-numrows/2,numrows/2),ofRandom(0,height));
      if(i==0){
        attractor[0].f = 1;
        attractor[0].pos.set(0,0,height/2);
      }
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
