class Model {
public:
    int counter;
    int vertexcounter;
    bool vforward;
    ofxAssimpModelLoader model;
    ofMesh mesh;
    ofMesh omesh;
    Model() {
        counter = 0;
        vertexcounter = 0;
        vforward = true;
        model.loadModel("heart.obj", false);
        model.setScale(1.25, 1.25, 1.25);
        mesh = model.getCurrentAnimatedMesh(0);
    }

    void clear() {
        mesh.clear();
    }

    void reset() {
      mesh = model.getCurrentAnimatedMesh(0);
    }

    void update() {
        counter = (counter + 1) % 1;
    }

    void render(int x, int y, int z){
        if(counter == 0) {
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
          vertexcounter += 1;
          for(int i=0;i<vertexcounter;i++){
            mesh.addVertex(omesh.getVertex(i));
          }
        }
        if(vforward == false){
          vertexcounter -= 1;
          for(int i=0;i<vertexcounter;i++){
            mesh.addVertex(omesh.getVertex(omesh.getNumVertices()-i));
          }
        }
      }
    }
    void wiggle(){
      for(int i = 0; i<mesh.getNumVertices()/2; i++){
        ofVec3f rvert;
        rvert.set(mesh.getVertex(i).x + 0.5,mesh.getVertex(i).y,mesh.getVertex(i).z);
        mesh.setVertex(i,rvert);
        rvert.set(mesh.getVertex(i+(mesh.getNumVertices()/2)).x - 0.5,mesh.getVertex(i+(mesh.getNumVertices()/2)).y,mesh.getVertex(i+(mesh.getNumVertices()/2)).z);
        mesh.setVertex(i+(mesh.getNumVertices()/2),rvert);
      }
    }
    void draw(int c, int a, float timer){
      ofPushMatrix();
      ofSetColor(c,a);
      ofFill();
      ofRotate(180,1,0,0);
      ofTranslate(model.getPosition().x, model.getPosition().y, model.getPosition().z);
      ofRotate(timer*100, 0, 1, 0);
      ofTranslate(-model.getPosition().x, -model.getPosition().y, -model.getPosition().z);
      ofxAssimpMeshHelper & meshHelper = model.getMeshHelper(0);
      ofMultMatrix(model.getModelMatrix());
      ofMultMatrix(meshHelper.matrix);
      mesh.drawWireframe();
      ofPopMatrix();
    }
    void drawraw(float timer){
      ofPushMatrix();
      ofTranslate(model.getPosition().x, model.getPosition().y, 0);
      ofRotate(timer*100, 0, 0, 1);
      ofTranslate(-model.getPosition().x, -model.getPosition().y, 0);
      model.drawFaces();
      ofPopMatrix();
    }
};
