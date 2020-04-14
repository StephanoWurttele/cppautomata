#include "tokens.h"

Token::Token(int _name, char character){
    content = ' ';
    switch (_name){
        case 0:
            name = L;
            break;
        case 1:
            name = N;
            break;
        case 2: 
            name = S;
            break;
        default:  
            name = O;
    }
};