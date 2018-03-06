#ifndef oscSender_h
#define oscSender_h

#include <iostream>
#include "ofxOsc.h"

class OscSender {
private:
    ofxOscSender sender;
    int port;
public:
    void sendFloat(std::string address, float message);
    void sendBang(std::string address);
    void changePort(int newPort);
    OscSender();
};

#endif
