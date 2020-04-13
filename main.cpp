#include "automata.h"
#include "scanner.h"
int main(int argc, char *argv[]){
    if (argc != 3){
        std::cout<<"Please enter automata file and mail only";
        return 0;
    };
    Automata email_tester(argv[1]);
    std::string mail = argv[2];
    std::vector<Token> TokenVec;
    email_tester.show();
    Scanner scanner;
    for (char c : mail)  
        TokenVec.push_back(scanner.scan(c));
    for (Token t : TokenVec)
        std::cout << t.type() << " ";
    std::cout << std::endl;
    email_tester.run(TokenVec);
    email_tester.accepted() ? std::cout << "Email is valid" : std::cout << "Email is not valid";
    
    return 0;
};