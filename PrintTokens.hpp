#include "Lexer.hpp"
#include <iostream>
#include <fstream>
void PrintTokens(Lexer& lexer,Token tok){
        while ((tok = lexer.nextToken()) != Token::END_OF_FILE) {
        std::cout << "Token: ";
        switch (tok) {
            case Token::NUMBER:
                std::cout << "NUMBER(" << lexer.getText() << ")";
                break;
            case Token::AND_OPERATOR:
            std::cout << "AND OPERATOR(" << lexer.getText() << ")";
                break;
            case Token::ASSIGN_OPERATOR:
            std::cout << "ASSIGN OPERATOR(" << lexer.getText() << ")";
                break;
            case Token::COMA:
            std::cout << "COMA(" << lexer.getText() << ")";
                break;
            case Token::DIVISION_OPERATOR:
            std::cout << "DIVISION OPERATOR(" << lexer.getText() << ")";
                break;
            case Token::EQUAL_OPERATOR:
            std::cout << "EQUAL OPERATOR(" << lexer.getText() << ")";
                break;
            case Token::GREATER_EQUAL_OPERATOR:
             std::cout << "GREATER_EQUAL OPERATOR(" << lexer.getText() << ")";
                break;
            case Token::GREATER_OPERATOR:
             std::cout << "GREATER OPERATOR(" << lexer.getText() << ")";
                break;
            case Token::IDENTIFIER:
             std::cout << "IDENTIFIER(" << lexer.getText() << ")";
                break;
            case Token::Keyword_else:
             std::cout << "KEYWORD_ELSE(" << lexer.getText() << ")";
                break;
            case Token::Keyword_if:
             std::cout << "KEYWORD_IF(" << lexer.getText() << ")";
                break;
            case Token::Keyword_int:
             std::cout << "KEYWORD_INT(" << lexer.getText() << ")";
                break;
            case Token::Keyword_print:
             std::cout << "KEYWORD PRINT(" << lexer.getText() << ")";
                break;
            case Token::Keyword_while:
             std::cout << "KEYRWORD WHILE(" << lexer.getText() << ")";
                break;
            case Token::LEFT_KEY:
             std::cout << "LEFT KEY(" << lexer.getText() << ")";
                break;
            case Token::LEFT_PAR:
             std::cout << "LEFT PARENTHESIS(" << lexer.getText() << ")";
                break;
            case Token::LESS_EQUAL_OPERATOR:
             std::cout << "LESS EQUAL OPERATOR(" << lexer.getText() << ")";
                break;
            case Token::LESS_OPERATOR:
             std::cout << "LESS THAN OPERATOR(" << lexer.getText() << ")";
                break;
            case Token::MODULE_OPERATOR:
             std::cout << "MODULE OPERATOR(" << lexer.getText() << ")";
                break;
            case Token::MULTIPLICATION_OPERATOR:
             std::cout << "MULTIPLICATION OPERATOR(" << lexer.getText() << ")";
                break;
            case Token::NOT_OPERATOR:
                std::cout << "NOT OPERATOR(" << lexer.getText() << ")";
                break;
            case Token::NOT_EQUAL_OPERATOR:
                std::cout << "NOT EQUAL OPERATOR(" << lexer.getText() << ")";
                break;
            case Token::OR_OPERATOR:
             std::cout << "OR OPERATOR(" << lexer.getText() << ")";
                break;
            case Token::RIGHT_KEY:
            std::cout << "RIGHT KEY(" << lexer.getText() << ")";
                break;
            case Token::RIGHT_PAR:
            std::cout << "RIGHT PARENTHESIS(" << lexer.getText() << ")";
                break;
            case Token::SEMICOLON:
            std::cout << "SEMICOLON(" << lexer.getText() << ")";
                break;
            case Token::SUBTRACTION_OPERATOR:
            std::cout << "SUBTRACTION_OPERATOR(" << lexer.getText() << ")";
                break;
            case Token::SUM_OPERATOR:
            std::cout << "SUM OPERATOR(" << lexer.getText() << ")";
                break;

            case Token::ERROR:
            std::cerr<<"CARACTER INVALIDO";
            break;
            default:
                break;
        }
        std::cout << '\n';
    }

    std::cout << "End of file.\n";
}