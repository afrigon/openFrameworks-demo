#pragma once

#include "ofMain.h"
#include "ofxAssimpModelLoader.h"

class Renderer {
    const double windowSize = 900;
    ofxAssimpModelLoader charlie;
    
public:
    ofLight light;
    void setup();
    void draw(double delta);
    void image_export(const string name, const string extension) const;
};
