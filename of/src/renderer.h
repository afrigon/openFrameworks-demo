#pragma once

#include <stack>
#include "ofMain.h"
#include "lsystem.hpp"

struct P {
    double x;
    double y;
    double heading = -90;
    P() {}
    P(double x, double y): x(x), y(y) {}
};

class Renderer {
    const double windowSize = 900;
    LSystem lsys;
    stack<P> posStack;
    P startPos = P(windowSize/2.0, windowSize);
    double lineLength = 15;
    double renderTime = 10;
    
public:
    void setup();
    void draw(double delta);
    void image_export(const string name, const string extension) const;
};
