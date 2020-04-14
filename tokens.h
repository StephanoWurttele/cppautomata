#ifndef TOKENS_H
#define TOKENS_H

enum tokens{L, N, S, O, Count}; //Letter, Number, Separator, Other
class Token{
    private:
    tokens name;
    char content;
    public:
    Token(){};
    Token(tokens _name, char character) : name(_name), content(character){};
    Token(int _name, char character);
    tokens type(){return name;};
};

#endif