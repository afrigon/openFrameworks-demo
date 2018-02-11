#include "application.h"

void Application::setup() {
    ofSetWindowTitle("Alexandre Frigon - Labo2");
    this->renderer.setup();
}

void Application::draw() {
    this->renderer.draw();
}

void Application::keyReleased(int key) {
    if (key == ' ') {
        this->renderer.image_export("render", "png");
    }
}
