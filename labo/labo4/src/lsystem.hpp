#ifndef lsystem_hpp
#define lsystem_hpp

#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

class Rule {
    char from;
    string to;
    
public:
    Rule(char from, string to): from(from), to(to) {}
    string apply(string current) {
        stringstream ss;
        for (char& c : current) ss << (c == from ? to : string(1, c));
        return ss.str();
    }
};

class LSystem {
    string current;
    string axiom;
    double angle;
    vector<Rule> rules;
    
public:
    LSystem() {}
    LSystem(string axiom, int angle = 90): current(axiom), axiom(axiom), angle(angle) {
        this->rules = vector<Rule>();
    }
    void addRule(char from, string to);
    void step(int steps = 1);
    string str();
    double getAngle();
};

#endif /* lsystem_hpp */
