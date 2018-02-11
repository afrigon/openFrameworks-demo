#include <sstream>
#include "renderer.h"

void Renderer::setup() {
    ofSetFrameRate(60);
    for (int i = 0; i < 9; ++i) {
        ofImage image;
        std::stringstream ss;
        ss << i << ".jpg";
        std::string filename = ss.str();
        image.load(filename);
        this->images.push_back(image);
    }
    ofSetWindowShape(this->windowSize, this->windowSize);
}

void Renderer::draw() {
    ofClear(0);
    ofSetColor(255);

    int width = ofGetWindowWidth();
    int height = ofGetWindowHeight();
    
    for (int y = 0; y < 3; ++y) {
        for (int x = 0; x < 3; ++x) {
            int xPos = this->padding * (x + 1) + this->imageSize * x;
            int yPos = this->padding * (y + 1) + this->imageSize * y;
            int width = this->imageSize;
            int height = this->imageSize;
            this->images[y * 3 + x].draw(xPos, yPos, width, height);
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
