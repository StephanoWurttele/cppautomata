#include "tokens.h"

Token::Token(int _name){
    switch (_name){
        case 0:
            name = W;
            break;
        case 1:
            name = A;
            break;
        case 2: 
            name = P;
            break;
        default:  
            name = O;
    }
};