#include "osc.h"

OscSender::OscSender() {
    port = 7400;
    sender.setup("localhost", port);
    std::cout << "Sending OSC messages to port " << port << "..." << "\n\n";
}

void OscSender::sendFloat(std::string address, float message) {
    ofxOscMessage m;
    m.setAddress(address);
    m.addFloatArg(message);
    sender.sendMessage(m);
}

void OscSender::sendBang(std::string address) {
    ofxOscMessage m;
    m.setAddress(address);
    m.addBoolArg(true);
    sender.sendMessage(m);
}

void OscSender::changePort(int newPort) {
    port = newPort;
}

