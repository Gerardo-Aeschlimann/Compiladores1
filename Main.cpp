#include "Lexer.hpp"
#include <fstream>
#include <iostream>

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

    while ((tok = lexer.nextToken()) != Token::END_OF_FILE) {
        std::cout << "Token: ";
        switch (tok) {
            case Token::NUMBER:
                std::cout << "NUMBER(" << lexer.getText() << ")";
                break;
            case Token::IDENTIFIER:
                std::cout << "IDENTIFIER(" << lexer.getText() << ")";
                break;
            default:
                break;
        }
        std::cout << '\n';
    }

    std::cout << "End of file.\n";
    return 0;
}