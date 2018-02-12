#include "lsystem.hpp"

void LSystem::addRule(char from, string to) {
    this->rules.push_back(Rule(from, to));
}

void LSystem::step(int steps) {
    for (int i = 0; i < steps; ++i) {
        for (int j = 0; j < this->rules.size(); ++j) {
            this->current = this->rules[j].apply(this->current);
        }
    }
}

string LSystem::str() {
    return this->current;
}

double LSystem::getAngle() {
    return this->angle;
}
