class Model {
public:
    int counter;
    int vertexcounter;
    bool vforward;
    float timer = 0;
    bool bang = false;
    bool active = false;
    ofxAssimpModelLoader model;
    ofMesh mesh;
    ofMesh omesh;
    void init(std::string s, float scale) {
        counter = 0;
        vertexcounter = 0;
        vforward = true;
        model.loadModel(s, false);
        model.setScale(scale, scale, scale);
        mesh = model.getCurrentAnimatedMesh(0);
    }
    void clear() {
        mesh.clear();
    }

    void reset() {
      mesh = model.getCurrentAnimatedMesh(0);
    }

    void render(int x, int y, int z, int divisor, int amt, int prob){
      if(active == true){
        counter = (counter + 1) % divisor;
        if(counter == 0) {
          int probability = ofRandom(0,100);
          if(probability < prob){
            bang = true;
            model.setPosition(x, y, z);
            model.update();
            mesh = model.getCurrentAnimatedMesh(0);
            if(vertexcounter <=0) {
              vforward = true;
            }
            if(vertexcounter >= mesh.getNumVertices()-1){
              vforward = false;
            }
            omesh = mesh;
            mesh.clear();
            if(vforward == true){
              vertexcounter += amt;
              for(int i=0;i<vertexcounter;i++){
                mesh.addVertex(omesh.getVertex(i));
              }
            }
            if(vforward == false){
              vertexcounter -= amt;
              for(int i=0;i<vertexcounter;i++){
                mesh.addVertex(omesh.getVertex(omesh.getNumVertices()-i));
              }
            }
          }
        }
      }
    }
    void wiggle(){
      for(int i = 0; i<mesh.getNumVertices()/2; i++){
        if(active == true){
          ofVec3f rvert;
          rvert.set(mesh.getVertex(i).x + 0.5,mesh.getVertex(i).y,mesh.getVertex(i).z);
          mesh.setVertex(i,rvert);
          rvert.set(mesh.getVertex(i+(mesh.getNumVertices()/2)).x - 0.5,mesh.getVertex(i+(mesh.getNumVertices()/2)).y,mesh.getVertex(i+(mesh.getNumVertices()/2)).z);
          mesh.setVertex(i+(mesh.getNumVertices()/2),rvert);
        }
      }
    }
    void draw(int c, int a, int rotatex, int rotatey, float speed){
      if(active == true){
        timer += speed;
        ofPushMatrix();
        ofSetColor(c,a);
        ofFill();
        ofRotate(rotatex,1,0,0);
        ofTranslate(model.getPosition().x, model.getPosition().y, model.getPosition().z);
        ofRotate(rotatey + timer, 0, 1, 0);
        ofTranslate(-model.getPosition().x, -model.getPosition().y, -model.getPosition().z);
        ofxAssimpMeshHelper & meshHelper = model.getMeshHelper(0);
        ofMultMatrix(model.getModelMatrix());
        ofMultMatrix(meshHelper.matrix);
        mesh.drawWireframe();
        ofPopMatrix();
      }
    }
    void drawraw(float timer){
      if(active == true){
        ofPushMatrix();
        ofTranslate(model.getPosition().x, model.getPosition().y, 0);
        ofRotate(timer*100, 0, 0, 1);
        ofTranslate(-model.getPosition().x, -model.getPosition().y, 0);
        model.drawFaces();
        ofPopMatrix();
      }
    }
};
