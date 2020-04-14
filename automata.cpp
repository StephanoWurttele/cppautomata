#include <fstream>
#include "automata.h"

Automata::Automata(std::string filename){
    unsigned NodeNum;
    std::string temp, ANode, targetNode, output;
    std::ifstream format(filename);
    getline(format, temp);
    NodeNum = std::stoi(temp);
    for(int i = 0; i < NodeNum; i++ ){
        getline(format,temp);
        getline(format, ANode);
        getline(format, output);
        State* tempS = new State(temp, ANode == "1", output);
        states.push_back(tempS);
    }
    for(int i = 0; i < NodeNum; ++i ){
        std::vector<Transition> vec;
        for(int j = 0; j < (int)tokens::Count; ++j){
            getline(format, targetNode);
            vec.emplace_back(j, FindState(targetNode));
        }
        transitions.push_back(vec);
    }
    current_state = states[0];
}

void Automata::run(std::vector<Token> TokenVec){
    std::cout << "Starting from state " << current_state->getName() << std::endl;
    for(Token t : TokenVec){
        std::cout << "Current state number is "<< current_state->number() << std::endl;
        for(Transition t2 : transitions[current_state->number()]){
            if (t2.path() == t.type()){
                if (t.type == S){
                    if (current_state->final)
                        output.push_back(current_state->getOutput);
                    else
                    {
                        output.clear;
                        output.push_back(current_state->getOutput);
                        return;
                    }
                    
                }
                current_state = t2.getTarget();
                std::cout << "Advanced to " << t2.getTarget()->getName() << " and current is " << current_state->getName() << std::endl;
            }
        }
    }
};

bool Automata::accepted(){
    return current_state->final();
}

State* Automata::FindState(std::string state){
    for (State* x:states){
        if  (x->getName() == state){
            return x;
        }
    }
}