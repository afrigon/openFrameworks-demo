#include <sstream>
#include "renderer.h"
using namespace std;

void Renderer::setup() {
    ofSetFrameRate(60);
    ofSetWindowShape(this->windowSize, this->windowSize);
    
    charlie.loadModel("charlie.obj");
    
    ofSetBackgroundAuto(true);
    ofBackground(0);
    ofEnableDepthTest();
    ofEnableLighting();
    
    light.setAmbientColor(ofColor(0, 255, 0));
    light.setDiffuseColor(ofColor(255, 255, 255));
    light.setPosition(0.0f, 0.0f, 1000.0f);
    light.enable();
}

void Renderer::draw(double delta) {
    ofFill();
    ofSetLineWidth(1.0f);
    ofSetColor(127);
    ofTranslate(ofGetWidth()/ 2.0f, ofGetHeight() - 150, 20);
    charlie.setRotation(0, 20.0f, 0.0f, 1.0f, 0.0f);
    charlie.draw(OF_MESH_FILL);
}

void Renderer::image_export(const string name, const string extension) const {
    ofImage image;
    string time_stamp = ofGetTimestampString("-%y%m%d-%H%M%S-%i");
    string file_name = name + time_stamp + "." + extension;
    image.grabScreen(0, 0, ofGetWindowWidth(), ofGetWindowHeight());
    image.save(file_name);
}
