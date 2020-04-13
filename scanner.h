#ifndef SCANNER_H
#define SCANNER_H

#include "tokens.h"

class Scanner{
    public:
    Scanner(){};
    static Token scan(char input);
};


#endif