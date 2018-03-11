class WtArray{
  public:
    int counter = 0;
    int scounter = 16;
    ofVec3f wta [4][128];
    int port = 7400;
    ofxOscSender sender;
    ofxOscMessage wtx [4];
    ofxOscMessage wty [4];
    ofxOscMessage wtz [4];
    void init(){
      ofxOscMessage wtreset;
      wtreset.setAddress("wtreset");
      sender.sendMessage(wtreset);
      for(int i=0;i<4;i++){
        wtx[i].clear();
        wty[i].clear();
        wtz[i].clear();
        wtx[i].setAddress("wtx" + std::to_string(i));
        wty[i].setAddress("wty" + std::to_string(i));
        wtz[i].setAddress("wtz" + std::to_string(i));
      }
    }
    void update(int i, int numrows, int numcols, int height, ofVec3f vertices){
      if(i>=0 && i<128){
        wta[0][i].set(abs((vertices.x)/(numrows))*0.9,abs((vertices.y)/(numcols))*0.9,abs((vertices.z-(height/2))/(height))*0.9);
        wtx[0].addFloatArg(wta[0][i].x);
        wty[0].addFloatArg(wta[0][i].y);
        wtz[0].addFloatArg(wta[0][i].z);
      }
      else if(i>=128 && i<256){
        wta[1][i-128].set(abs((vertices.x)/(numrows))*0.9,abs((vertices.y)/(numcols))*0.9,abs((vertices.z-(height/2))/(height))*0.9);
        wtx[1].addFloatArg(wta[1][i-128].x);
        wty[1].addFloatArg(wta[1][i-128].y);
        wtz[1].addFloatArg(wta[1][i-128].z);
      }
      else if(i>=256 && i<384){
        wta[2][i-256].set((abs((vertices.x)/(numrows))*0.9)*-1,(abs((vertices.y)/(numcols))*0.9)*-1,(abs((vertices.z-(height/2))/(height))*0.9)*-1);
        wtx[2].addFloatArg(wta[2][i-256].x);
        wty[2].addFloatArg(wta[2][i-256].y);
        wtz[2].addFloatArg(wta[2][i-256].z);
      }
      else if(i>=384 && i<512){
        wta[3][i-384].set((abs((vertices.x)/(numrows))*0.9)*-1,(abs((vertices.y)/(numcols))*0.9)*-1,(abs((vertices.z-(height/2))/(height))*0.9)*-1);
        wtx[3].addFloatArg(wta[3][i-384].x);
        wty[3].addFloatArg(wta[3][i-384].y);
        wtz[3].addFloatArg(wta[3][i-384].z);
      }
    }
    void send(){
      for(int i=0;i<4;i++){
        sender.sendMessage(wtx[i]);
        sender.sendMessage(wty[i]);
        sender.sendMessage(wtz[i]);
        wtx[i].clear();
        wty[i].clear();
        wtz[i].clear();
        wtx[i].setAddress("wtx" + std::to_string(i));
        wty[i].setAddress("wty" + std::to_string(i));
        wtz[i].setAddress("wtz" + std::to_string(i));
      }
    }
};
