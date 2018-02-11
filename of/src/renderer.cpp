#include <sstream>
#include "renderer.h"

void Renderer::setup() {
    ofSetFrameRate(60);
    ofSetWindowShape(this->windowSize, this->windowSize);
}

void Renderer::draw() {
    ofClear(0);
    ofSetColor(255);

    int windowWidth = ofGetWindowWidth();
    int windowHeight = ofGetWindowHeight();
}

void Renderer::image_export(const string name, const string extension) const {
    ofImage image;
    string time_stamp = ofGetTimestampString("-%y%m%d-%H%M%S-%i");
    string file_name = name + time_stamp + "." + extension;
    image.grabScreen(0, 0, ofGetWindowWidth(), ofGetWindowHeight());
    image.save(file_name);
}
