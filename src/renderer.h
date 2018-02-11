#pragma once

#include <vector>
#include "ofMain.h"

class Renderer {
    std::vector<ofImage> images;
    const int windowSize = 900;
    const int padding = 30;
    const int imageSize = (this->windowSize - 4 * this->padding) / 3;
    
public:
    void setup();
    void draw();
    void image_export(const string name, const string extension) const;
};
