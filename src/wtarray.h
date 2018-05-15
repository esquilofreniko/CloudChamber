class WtArray{
  public:
    int counter = 0;
    int scounter = 16;
    ofVec3f wta [4][128];
    double wtx[4][128];
    void update(int width, int height, int depth, ofVec3f vertices[512]){
      for(int i=0;i<512;i++){
        if(i>=0 && i<128){
          wta[0][i] = ofVec3f(abs((vertices[i].x)/(width))*0.9,abs((vertices[i].y)/(height))*0.9,abs((vertices[i].z)/(depth))*0.9);
          wtx[0][i] = abs(vertices[i].x/width);
        }
        else if(i>=128 && i<256){
          wta[1][i-128] = ofVec3f(abs((vertices[i].x)/(width))*0.9,abs((vertices[i].y)/(height))*0.9,abs((vertices[i].z)/(depth))*0.9);
          wtx[1][i-128] = abs(vertices[i].x/width);
        }
        else if(i>=256 && i<384){
          wta[2][i-256] = ofVec3f((abs((vertices[i].x)/(width))*0.9)*-1,(abs((vertices[i].y)/(height))*0.9)*-1,(abs((vertices[i].z)/(depth))*0.9)*-1);
          wtx[2][i-256] = abs(vertices[i].x/width);
        }
        else if(i>=384 && i<512){
          wta[3][i-384] = ofVec3f((abs((vertices[i].x)/(width))*0.9)*-1,(abs((vertices[i].y)/(height))*0.9)*-1,(abs((vertices[i].z)/(depth))*0.9)*-1);
          wtx[3][i-384] = abs(vertices[i].x/width);
        }
      }
      for(int j=0;j<4;j++){
        std::sort(wtx[j],wtx[j+127]);
        cout << wtx[j][127] << endl;
      }
    }
};
