#pragma once

#include "ofMain.h"
#include "renderer.h"

struct Application : public ofBaseApp {
    Renderer renderer;
    
    void setup();
    void draw();
    void keyReleased(int key);
};
