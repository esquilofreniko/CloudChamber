class Space {
  public:
    ofCamera cam;
    ofVec3f campos;
    ofPlanePrimitive planes [6];
    int camx = 0;
    int camy = 0;
    int camz = 10;
    int numcols;
    int numrows;
    int height;
    void init(int _numcols, int _numrows, int _height){
      numcols = _numcols;
      numrows = _numrows;
      height = _height;
      cam.tilt(180);
      cam.setPosition(camx,camy,camz);
      planes[0].set(numcols,numrows);
      planes[0].setPosition(0,0,0);
      planes[0].setResolution(numcols/8,numrows/8);
      planes[1].set(numcols,numrows);
      planes[1].setPosition(0,0,height);
      planes[1].setResolution(numcols/8,numrows/8);
      planes[2].set(numcols,numrows);
      planes[2].setPosition(0,numrows/2,height/2);
      planes[2].setResolution(numcols/8,numrows/8);
      planes[2].rotate(90,1,0,0);
      planes[3].set(numcols,numrows);
      planes[3].setPosition(0,-numrows/2,height/2);
      planes[3].setResolution(numcols/8,numrows/8);
      planes[3].rotate(90,1,0,0);
      planes[4].set(numcols,numrows);
      planes[4].setPosition(numcols/2,0,height/2);
      planes[4].setResolution(numcols/8,numrows/8);
      planes[4].rotate(90,0,1,0);
      planes[5].set(numcols,numrows);
      planes[5].setPosition(-numcols/2,0,height/2);
      planes[5].setResolution(numcols/8,numrows/8);
      planes[5].rotate(90,0,1,0);
    }
    void update(){
      campos = cam.getPosition();
      if(campos.x<(-numcols/2)+10){
        cam.setPosition((-numcols/2)+10,campos.y,campos.z);
      }
      if (campos.x>(numcols/2)-10){
        cam.setPosition((numcols/2)-10,campos.y,campos.z);
      }
      if(campos.y<(-numrows/2)+10){
        cam.setPosition(campos.x,(-numrows/2)+10,campos.z);
      }
      if (campos.y>(numrows/2)-10){
        cam.setPosition(campos.x,(numrows/2)-10,campos.z);
      }
      if (campos.z<0+10){
        cam.setPosition(campos.x,campos.y,0+10);
      }
      if(campos.z>height-10){
        cam.setPosition(campos.x,campos.y,height-10);
      }
    }
};

// ofEnableLighting();
// ofColor white(255,255,255,255);
// ofColor red(255,0,0,255);
// ofColor green(0,255,0,255);
// ofColor blue(0,0,255,255);
// ofColor purple(255,0,255,255);
// light[0].setPointLight();
// light[0].setDiffuseColor(white);
// light[0].setPosition(0,0,0);
// light[0].enable();
// light[1].setDirectional();
// light[1].setDiffuseColor(white);
// light[1].setPosition(0,0,100);
// light[1].enable();
// light[2].setPointLight();
// light[2].setDiffuseColor(white);
// light[2].setPosition(0,0,50);
// light[2].enable();
// light[3].setPointLight();
// light[3].setDiffuseColor(white);
// light[3].setPosition(0,0,50);
// light[3].enable();
