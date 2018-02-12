#include <sstream>
#include "renderer.h"
using namespace std;

void Renderer::setup() {
    ofSetFrameRate(60);
    ofSetWindowShape(this->windowSize, this->windowSize);
    
    lsys = LSystem("F", 22);
    lsys.addRule('F', "FF-[-F+F+F]+[+F-F-F]");
    lsys.step(4);

//    lsys = LSystem("F-G-G", 120);
//    lsys.addRule('F', "F-G+F+G-F");
//    lsys.addRule('G', "GG");
//    lsys.step(6);
    
    ofSetBackgroundAuto(true);
    ofBackground(0);
    ofSetLineWidth(2);
}

void Renderer::draw(double delta) {
    P pos = P(startPos.x, startPos.y);
    double time = ofGetElapsedTimef();
    int renderCount = min((double)lsys.str().size(), time * lsys.str().size() / renderTime);
    for (int i = 0; i < renderCount; ++i) {
        char& c = lsys.str()[i];
        switch (c) {
            case '+':
                pos.heading += lsys.getAngle();
                break;
            case '-':
                pos.heading -= lsys.getAngle();
                break;
            case '[':
                posStack.push(pos);
                break;
            case ']':
                pos = posStack.top();
                posStack.pop();
                break;
            default:
                double lastX = pos.x;
                double lastY = pos.y;
                
                double rad = pos.heading * (pi/180);
                pos.x += lineLength * cos(rad);
                pos.y += lineLength * sin(rad);
                
                ofDrawLine(lastX, lastY, pos.x, pos.y);
        }
    }
}

void Renderer::image_export(const string name, const string extension) const {
    ofImage image;
    string time_stamp = ofGetTimestampString("-%y%m%d-%H%M%S-%i");
    string file_name = name + time_stamp + "." + extension;
    image.grabScreen(0, 0, ofGetWindowWidth(), ofGetWindowHeight());
    image.save(file_name);
}
