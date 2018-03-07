class Attractor {
public:
    int nvert = 512;
    ofVec3f pos;
    ofMesh mesh[2];
    ofVec3f vertices [2][512];
    float f;
    // ofLight light;
    void update(int i,float timer, ofVec3f randi) {
        int rad = 125;
        vertices[0][i].set(pos.x + (ofNoise(timer+randi.x)*(rad*2)-rad), pos.y + (ofNoise(timer+randi.y)*(rad*2)-rad), pos.z + (ofNoise(timer+randi.z)*(rad*2)-rad));
        vertices[1][i].set(pos.x + ((ofNoise(timer+randi.x)*(rad*2)-rad)/2), pos.y + ((ofNoise(timer+randi.y)*(rad*2)-rad)/2), pos.z + ((ofNoise(timer+randi.z)*(rad*2)-rad)/2));
        // light.setPointLight();
        // light.setPosition(pos.x,pos.y,pos.z);
    }
    void draw(int c,int a,int c2, int a2) {
      // light.enable();
      ofSetColor(c,a);
      ofFill();
      mesh[0].setMode(OF_PRIMITIVE_TRIANGLE_FAN);
      mesh[0].clearVertices();
      mesh[0].addVertices(vertices[0],nvert);
      mesh[0].draw();
      ofSetColor(c2,a2);
      ofFill();
      mesh[1].setMode(OF_PRIMITIVE_TRIANGLE_FAN);
      mesh[1].clearVertices();
      mesh[1].addVertices(vertices[1],nvert);
      mesh[1].draw();
    }
};

class Points {
public:
    int nvert = 512;
    ofVec3f vertices [512];
    ofVec3f vel [512];
    ofVec3f acc [512];
    ofMesh shapegen;
    void init(int i, int x, int y, int z, ofVec3f v) {
        vertices[i].set(x,y,z);
        vel[i] = v;
    }
    void update(int i, int numcols, int numrows, int height) {
        vertices[i] += vel[i];
        vel[i] += acc[i];
        acc[i] = acc[i]*0;
        if(vertices[i].x>numcols || vertices[i].x<-numcols) {
            vel[i].x *= -1;
        }
        if(vertices[i].y>numrows || vertices[i].y<-numrows) {
            vel[i].y *= -1;
        }
        if(vertices[i].z>height || vertices[i].z<0) {
            vel[i].z *= -1;
        }
        if(vertices[i].x>numcols){
          vertices[i].x = numcols;
        }
        if(vertices[i].x<-numcols){
          vertices[i].x = -numcols;
        }
        if(vertices[i].y>numrows){
          vertices[i].y = numrows;
        }
        if(vertices[i].y<-numrows){
          vertices[i].y = -numrows;
        }
        if(vertices[i].z > height){
          vertices[i].z = height;
        }
        if(vertices[i].z < 0){
          vertices[i].z = 0;
        }
    }
    void attracted(int i,ofVec3f target, float f, int numattractors) {
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
    void draw(int c, int a) {
        ofSetColor(c,a);
        ofFill();
        shapegen.setMode(OF_PRIMITIVE_POINTS);
        glPointSize(1);
        shapegen.clearVertices();
        shapegen.addVertices(vertices,nvert);
        shapegen.draw();
    }
};
