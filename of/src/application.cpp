#include "application.h"

void Application::setup() {
    ofSetWindowTitle("Alexandre Frigon - Labo");
    this->renderer.setup();
}

void Application::draw() {
    this->renderer.draw(time_elapsed);
}

void Application::update() {
    time_current = ofGetElapsedTimef();
    time_elapsed = time_current - time_last;
    time_last = time_current;
}

void Application::keyReleased(int key) {
    if (key == 'r') this->renderer.image_export("render", "png");
}
