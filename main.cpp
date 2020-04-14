#include "automata.h"
#include "scanner.h"
int main(int argc, char *argv[]){
    if (argc != 3){
        std::cout<<"Please enter automata file and mail only";
        return 0;
    };
    Automata reader(argv[1]);
    std::string input_line = argv[2];
    std::vector<Token> TokenVec;
    reader.show();
    Scanner scanner;
    for (char c : input_line)
        TokenVec.push_back(scanner.scan(c));
    for (Token t : TokenVec)
        std::cout << t.type() << " ";
    std::cout << std::endl;
    reader.run(TokenVec);
    reader.accepted() ? std::cout << "Email is valid" : std::cout << "Email is not valid";
    
    return 0;
};