#ifndef STATE_H
#define STATE_H

#include <iostream>
#include <string>

class State{
    private:
        std::string name = "";
        std::string output;
        bool acceptance;
    public:
        State(std::string _name, bool _end, std::string _output):name(_name), acceptance(_end), output(_output){};
        bool final(){return acceptance;};
        std::string getName(){return name;};
        std::string getOutput(){return output;};
        int number(){return std::stoi(name.substr(1));};
};
#endif