#include "scanner.h"

bool letter(char character)
{
    return (character >= 'A' && character <= 'Z') || (character >= 'a' && character <= 'z') || (character == '_');
}

bool number(char character){
    return (character >= '0' && character <= '9');
}

Token Scanner::scan(char input){
    tokens token;
    if (letter(input))
        token = L;
    else if (number(input))
        token = N;
    else if (input == '\n' || ' '){
                token = S;
    }
    else{
        token = O;
    }
    return Token(token, input);
}