#pragma once

#include "ofMain.h"
#include "renderer.h"

struct Application : public ofBaseApp {
    Renderer renderer;
    
    float time_current;
    float time_last;
    float time_elapsed;
    
    void setup();
    void draw();
    void update();
    void keyReleased(int key);
};
