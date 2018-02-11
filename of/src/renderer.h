#pragma once

#include "ofMain.h"

class Renderer {
    const int windowSize = 900;
    
public:
    void setup();
    void draw();
    void rec();
    void image_export(const string name, const string extension) const;
};
