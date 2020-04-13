#include "scanner.h"

bool w(char character)
{
    return (character >= 'A' && character <= 'Z') || (character >= 'a' && character <= 'z') || (character >= '0' && character <= '9') || (character == '_');
}

Token Scanner::scan(char input){
    tokens token;
    if (w(input))
        token = W;
    else{
        switch (input){
            case '@':
                token = A;
                break;
            case '.': 
                token = P;
                break;
            default:  
                token = O;
        }
    }
    return Token(token);
}