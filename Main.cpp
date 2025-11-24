#include "Lexer.hpp"
#include <fstream>
#include <iostream>
#include "PrintTokens.hpp"
#include "Parser.hpp"

int main(int argc, char* argv[]) {
    if (argc != 3) {
        std::cerr << "Missing arguments\n";
        return 1;
    }

    std::ifstream in(argv[1]);
    if (!in) {
        std::cerr << "Could not open file\n";
        return 1;
    }
    std::string modo=argv[2];
    Lexer lexer(in);
    Token tok;
    if(modo=="lexer"){
    PrintTokens(lexer,tok);
    }
    else if(modo=="parser"){
    Parser parser(lexer,tok);
    parser.Parse();
    std::cout<<"Fin Parser;";
    }else{
        std::cerr<<"MODO INVALIDO!\nPor favor ingrese: lexer | parser\n";
    }
    
    return 0;
}