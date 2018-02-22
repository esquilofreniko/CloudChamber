class Attractor{
  public:
    ofVec3f pos;
    ofSpherePrimitive sphere;
    void draw(int c,int a,int r){
      sphere.setPosition(pos);
      sphere.setRadius(r);
      ofColor(c,a);
      ofFill();
      sphere.draw();
    }
};

class Points {
public:
  int nvert = 1;
  ofVec3f vertices [512];
  ofVec3f prevpos [512];
  ofVec3f vel [512];
  ofVec3f acc [512];
  ofMesh shapegen;
  void init(int i, int x, int y, int z, ofVec3f v){
    vertices[i].set(x,y,z);
    vel[i] = v;
  }
  void update(int i,int numcols,int numrows,int height){
    vertices[i] += vel[i];
    vel[i] += acc[i];
    acc[i] = acc[i]*0;
    if(vertices[i].x>numcols || vertices[i].x<-numcols){
      vel[i].x *= -1;
    }
    if(vertices[i].y>numrows || vertices[i].y<-numrows){
      vel[i].y *= -1;
    }
    if(vertices[i].z>height || vertices[i].z<0){
      vel[i].z *= -1;
    }
    prevpos[i] = vertices[i];
  }
  void attracted(int i,ofVec3f target){
    ofVec3f force = target - vertices[i];
    float dsquared = pow(force.length(),2);
    if(dsquared<25){
      dsquared = 25;
    }
    if(dsquared>500){
      dsquared = 500;
    }
    float g = 6.67408;
    float strength = g/dsquared;
    strength = strength * 0.01;
    force.limit(strength);
    acc[i] += force;
  }
  void draw(int c, int a){
    ofSetColor(c,a);
    ofFill();
    shapegen.setMode(OF_PRIMITIVE_POINTS);
    glPointSize(1);
    shapegen.clearVertices();
    shapegen.addVertices(vertices,nvert);
    shapegen.draw();
  }
};
