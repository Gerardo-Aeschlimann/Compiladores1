#include "Lexer.hpp"
#include <fstream>
#include <iostream>
#include "PrintTokens.hpp"
#include "Parser.hpp"
int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Missing argument\n";
        return 1;
    }

    std::ifstream in(argv[1]);
    if (!in) {
        std::cerr << "Could not open file\n";
        return 1;
    }

    Lexer lexer(in);
    Token tok;
    Parser parser(lexer,tok);
    parser.Parse();
    //PrintTokens(lexer,tok);
    return 0;
}