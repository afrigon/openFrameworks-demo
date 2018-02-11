#include "application.h"

void Application::setup() {
    ofSetWindowTitle("Alexandre Frigon - Labo");
    this->renderer.setup();
}

void Application::draw() {
    this->renderer.draw();
}

void Application::keyReleased(int key) {
    if (key == 'r') this->renderer.image_export("render", "png");
}
