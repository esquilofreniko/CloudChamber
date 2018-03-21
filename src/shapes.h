class Lines {
public:
    int nvert = 0;
    ofVec3f vertices [512];
    ofVec3f pos;
    ofMesh shapegen;
    ofSpherePrimitive sphere;
    ofLight light;
    int rad = 0;
    bool active = false;
    bool bang = false;
    void clear(int width, int height, int depth, int _rad){
      nvert = 0;
      rad = _rad;
      pos.set(ofRandom(-width/4,width/4),0,ofRandom(-depth/4,depth/4));
      sphere.setPosition(pos);
      sphere.set(_rad,_rad);
      light.disable();
      light.setup();
      light.setPointLight();
      light.setAttenuation(1,(0.0000025),(0.0000025));
      light.setPosition(pos.x,pos.y,pos.z);
    }
    void update(int width, int height, int depth, int prob){
      if(active == true){
        int probability = ofRandom(0,100);
        if(prob>probability){
          bang = true;
          float heightrand = ofRandom(0,2);
          int height2 = 0;
          if(heightrand<1){
            height2 = -height/2;
          }
          if(heightrand>=1){
            height2 = height/2;
          }
          vertices[nvert].set(pos.x,pos.y,pos.z);
          vertices[nvert+1].set(ofRandom(-width/2,width/2),height2,ofRandom(-depth/2,depth/2));
          nvert += 2;
          nvert %= 512;
        }
      }
    }
    void draw(int r, int g, int b, int a) {
      if(active == true){
        light.setDiffuseColor(ofColor(r,g,b));
        light.enable();
        ofSetColor(r,g,b,a/4);
        shapegen.setMode(OF_PRIMITIVE_LINE_LOOP);
        shapegen.clearVertices();
        shapegen.addVertices(vertices,nvert);
        shapegen.draw();
        ofSetColor(r,g,b,a);
        sphere.drawWireframe();
      }
    }
};

class Shapes {
public:
    int nvert = 8;
    ofVec3f vertices [1000];
    ofMesh shapegen;
    void draw(int c, int a) {
        ofSetColor(c,a);
        ofFill();
        shapegen.setMode(OF_PRIMITIVE_TRIANGLE_FAN);
        shapegen.clearVertices();
        shapegen.addVertices(vertices,nvert);
        shapegen.draw();
	}
};

class Mesh {
public:
    int nvert = 16;
    ofMesh meshgen;
    void init(int xmin, int ymin, int zmin, int xmax,int ymax,int zmax) {
        meshgen.clear();
        for (int i = 0; i<nvert; i++) {
            meshgen.setMode(OF_PRIMITIVE_TRIANGLE_STRIP);
            meshgen.addVertex(ofPoint(ofRandom(xmin,xmax),ofRandom(ymin,ymax),ofRandom(zmin,zmax)));
            meshgen.addIndex(i);
        }
    }
    void draw(int c,int a) {
        ofSetColor(c,a);
        ofFill();
        meshgen.draw();
    }
};
