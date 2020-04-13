#ifndef TOKENS_H
#define TOKENS_H

enum tokens{W, A, P, O, Count};
class Token{
    private:
    tokens name;
    public:
    Token(){};
    Token(tokens _name) : name(_name){};
    Token(int _name);
    tokens type(){return name;};
};

#endif