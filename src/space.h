class Space {
private:
    int camx = 0;
    int camy = 0;
    int camz = 0;
    ofVec3f campos;
    ofPlanePrimitive planes [6];
    ofBoxPrimitive box;
public:
    bool framedraw = true;
    int width = 1000;
    int height = 1000;
    int depth = 1000;
    ofCamera cam;
    void drawBackground(int c, int a){
      ofSetColor(c,c,c,a);
      box.draw();
    }
    void drawWireframe(int c,int a) {
      if(framedraw == true){
        ofSetColor(c, a);
        for (int i = 0; i < 6; ++i){
          if(i != 1){
            planes[i].drawWireframe();
          }
        }
      }
    }
    Space() {
        camx = 0;
        camy = 0;
        camz = (depth/2)+250;
        // cam.setFov(75);
        box.setPosition(0,0,0);
        box.set(width*4,height*4,depth*4);
        cam.setPosition(camx,camy,camz);
        planes[0].set(width,height);
        planes[0].setPosition(0,0,-depth/2);
        planes[0].setResolution(width/8,height/8);
        planes[1].set(width,height);
        planes[1].setPosition(0,0,depth/2);
        planes[1].setResolution(width/8,height/8);
        planes[1].rotate(180,0,1,0);
        planes[2].set(width,height);
        planes[2].setPosition(0,height/2,0);
        planes[2].setResolution(width/8,height/8);
        planes[2].rotate(90,1,0,0);
        planes[3].set(width,height);
        planes[3].setPosition(0,-height/2,0);
        planes[3].setResolution(width/8,height/8);
        planes[3].rotate(270,1,0,0);
        planes[4].set(width,height);
        planes[4].setPosition(width/2,0,0);
        planes[4].setResolution(width/8,height/8);
        planes[4].rotate(270,0,1,0);
        planes[5].set(width,height);
        planes[5].setPosition(-width/2,0,0);
        planes[5].setResolution(width/8,height/8);
        planes[5].rotate(90,0,1,0);
    }
    void update() {
        campos = cam.getPosition();
        if(campos.x<(-width/2)+10) {
            cam.setPosition((-width/2)+10,campos.y,campos.z);
        }
        if (campos.x>(width/2)-10){
            cam.setPosition((width/2)-10,campos.y,campos.z);
        }
        if(campos.y<(-height/2)+10){
            cam.setPosition(campos.x,(-height/2)+10,campos.z);
        }
        if (campos.y>(height/2)-10){
            cam.setPosition(campos.x,(height/2)-10,campos.z);
        }
        if (campos.z<(-depth/2)+10){
            cam.setPosition(campos.x,campos.y,(-depth/2)+10);
        }
        if(campos.z>(depth/2)-10){
            cam.setPosition(campos.x,campos.y,(depth/2)-10);
        }
    }
    void movecam(int key){
      if(key == 'w'){
        cam.dolly(-1);
      }
      else if(key == 's'){
        cam.dolly(1);
      }
      if(key == 'a'){
        cam.pan(4);
      }
      else if(key == 'd'){
        cam.pan(-4);
      }
      if(key == 'e'){
        cam.tilt(1);
      }
      else if(key == 'q'){
        cam.tilt(-1);
      }
    }
};
