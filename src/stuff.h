class Lines {
	public:
		int nvert = 8;
		ofVec3f vertices [1000];
		ofMesh shapegen;
		void draw(int c, int a){
			ofSetColor(c,a);
			ofFill();
			shapegen.setMode(OF_PRIMITIVE_LINE_LOOP);
			shapegen.clearVertices();
			shapegen.addVertices(vertices,nvert);
			shapegen.draw();
		}
};

class Points {
	public:
		int nvert = 8;
		ofVec3f vertices [1000];
		ofMesh shapegen;
		void draw(int c, int a){
			ofSetColor(c,a);
			ofFill();
			shapegen.setMode(OF_PRIMITIVE_POINTS);
			shapegen.clearVertices();
			shapegen.addVertices(vertices,nvert);
			shapegen.draw();
		}
};

class Shapes {
public:
	int nvert = 8;
	ofVec3f vertices [1000];
	ofMesh shapegen;
	void draw(int c, int a){
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
		void init(int xmin, int ymin, int zmin, int xmax,int ymax,int zmax){
			meshgen.clear();
			for (int i = 0; i<nvert; i++){
					meshgen.setMode(OF_PRIMITIVE_TRIANGLE_STRIP);
					meshgen.addVertex(ofPoint(ofRandom(xmin,xmax),ofRandom(ymin,ymax),ofRandom(zmin,zmax)));
					meshgen.addIndex(i);
				}
			}
			void draw(int c,int a){
			ofSetColor(c,a);
			ofFill();
			meshgen.draw();
		}
};
