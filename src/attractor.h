class Attractor {
public:
    int nvert = 512;
    ofVec3f randi[512];
    ofVec3f pos;
    ofMesh mesh[2];
    ofVec3f vertices [2][512];
    float f;
    ofLight light;
    ofVec3f vel;
    ofVec3f acc;
    int rad;
    float timer = 0;
    float speed = 0.005;
    Attractor(){
      for(int i=0;i<nvert;i++){
        randi[i].set(ofRandom(0,500),ofRandom(0,500),ofRandom(0,500));
      }
    }
    void init(int x, int y, int z) {
      vel.set(0,0,0);
      f = ofRandom(-4, 4);
      pos.set(ofRandom(-x/4,x/4),ofRandom(-y/4,y/4),ofRandom(-z/4,z/4));
    }
    void change() {
      vel.set(0,0,0);
      f = ofRandom(-4,4);
    }
    void lighton() {
      light.setup();
      light.setPointLight();
      if(f != 0){
        light.setAttenuation(1,(0.000001/(abs(f))),(0.000001/(abs(f))));
      }
      light.setPosition(pos.x,pos.y,pos.z);
      light.enable();
      if(f == 0){
        light.disable();
      }
    }
    void limit(int numcols,int numrows, int height){
      if(pos.x>numcols/2 || pos.x<-numcols/2) {
          vel.x *= -0.95;
      }
      if(pos.y>numrows/2 || pos.y<-numrows/2) {
          vel.y *= -0.95;
      }
      if(pos.z>height/2 || pos.z<-height/2) {
          vel.z *= -0.95;
      }
      if(pos.x>numcols/2){
        pos.x = numcols/2;
      }
      if(pos.x<-numcols/2){
        pos.x = -numcols/2;
      }
      if(pos.y>numrows/2){
        pos.y = numrows/2;
      }
      if(pos.y<-numrows/2){
        pos.y = -numrows/2;
      }
      if(pos.z > height/2){
        pos.z = height/2;
      }
      if(pos.z < -height/2){
        pos.z = -height/2;
      }
    }
    void update(int _rad) {
      speed = abs(f)*0.005;
      timer += speed;
      for(int i=0;i<512;i++){
        rad = _rad;
        vertices[0][i].set(pos.x + (ofNoise(timer+randi[i].x)*(rad*2)-rad), pos.y + (ofNoise(timer+randi[i].y)*(rad*2)-rad), pos.z + (ofNoise(timer+randi[i].z)*(rad*2)-rad));
        vertices[1][i].set(pos.x + ((ofNoise(timer+randi[i].x)*(rad*2)-rad)/2), pos.y + ((ofNoise(timer+randi[i].y)*(rad*2)-rad)/2), pos.z + ((ofNoise(timer+randi[i].z)*(rad*2)-rad)/2));
      }
    }
    void draw(int a, int a2) {
      ofSetColor(0,(a*abs(f)+5));
      mesh[0].setMode(OF_PRIMITIVE_TRIANGLE_FAN);
      mesh[0].clearVertices();
      mesh[0].addVertices(vertices[0],nvert);
      mesh[0].draw();
      if(f>=0){
        light.setDiffuseColor(ofColor(255,255,255));
        ofSetColor(255,(a2*abs(f))+5);
      }
      if(f<0){
        light.setDiffuseColor(ofColor(255,0,0));
        ofSetColor(255,0,0,(a2*abs(f))+5);
      }
      mesh[1].setMode(OF_PRIMITIVE_TRIANGLE_FAN);
      mesh[1].clearVertices();
      mesh[1].addVertices(vertices[1],nvert);
      mesh[1].draw();
    }
    void attracted(ofVec3f target, float f, int numattractors) {
        ofVec3f force = target - pos;
        float dsquared = pow(force.length(),2);
        if(dsquared<5) {
            dsquared = 5;
        }
        if(dsquared>500) {
            dsquared = 500;
        }
        float g = 6.67408;
        float strength = g/dsquared;
        strength = (strength * 0.01)/numattractors;
        force.limit(strength);
        force *= f;
        acc += force;
        pos += vel;
        vel += acc;
        acc = acc*0;
    }
};

class Points {
  public:
    int nvert = 512;
    ofVec3f vertices [512];
    ofVec3f vel [512];
    ofVec3f acc [512];
    ofMesh shapegen;
    Points() {
      glPointSize(1);
    }
    void init(int x, int y, int z) {
      for(int i=0;i<nvert;i++){
        vertices[i].set(ofRandom(-x/2,x/2),ofRandom(-y/2,y/2),ofRandom(-z/2,z/2));
        vel[i].set(0,0,0);
      }
    }
    void stop(){
      for(int i=0;i<nvert;i++){
        vel[i].set(0,0,0);
      }
    }
    void update(int numcols, int numrows, int height) {
      for(int i=0;i<nvert;i++){
        vertices[i] += vel[i];
        vel[i] += acc[i];
        acc[i] = acc[i]*0;
        if(vertices[i].x>numcols/2 || vertices[i].x<-numcols/2) {
          vel[i].x *= -0.95;
        }
        if(vertices[i].y>numrows/2 || vertices[i].y<-numrows/2) {
          vel[i].y *= -0.95;
        }
        if(vertices[i].z>height/2 || vertices[i].z<-height/2) {
          vel[i].z *= -0.95;
        }
        if(vertices[i].x>numcols/2){
          vertices[i].x = numcols/2;
        }
        if(vertices[i].x<-numcols/2){
          vertices[i].x = -numcols/2;
        }
        if(vertices[i].y>numrows/2){
          vertices[i].y = numrows/2;
        }
        if(vertices[i].y<-numrows/2){
          vertices[i].y = -numrows/2;
        }
        if(vertices[i].z > height/2){
          vertices[i].z = height/2;
        }
        if(vertices[i].z < -height/2){
          vertices[i].z = -height/2;
        }
      }
    }
    void attracted(ofVec3f target, float f, int numattractors) {
      for(int i=0;i<nvert;i++){
        ofVec3f force = target - vertices[i];
        float dsquared = pow(force.length(),2);
        if(dsquared<5) {
          dsquared = 5;
        }
        if(dsquared>500) {
          dsquared = 500;
        }
        float g = 6.67408;
        float strength = g/dsquared;
        strength = (strength * 0.01)/numattractors;
        force.limit(strength);
        force *= f;
        acc[i] += force;
      }
    }
    void draw(int c, int a, int prob) {
      int rands;
      rands = ofRandom(0,100);
      if(rands>=prob){
        ofSetColor(c, a);
        shapegen.setMode(OF_PRIMITIVE_POINTS);
      }
      else if(rands<prob){
        ofSetColor(c, a*0.125);
        shapegen.setMode(OF_PRIMITIVE_LINE_LOOP);
      }
      shapegen.clearVertices();
      shapegen.addVertices(vertices,nvert);
      shapegen.draw();
    }
};
