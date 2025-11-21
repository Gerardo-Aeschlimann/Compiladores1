#include "Lexer.hpp"
#include <iostream>
#include <fstream>
void PrintTokens(Lexer& lexer,Token tok){
        while ((tok = lexer.nextToken()) != Token::END_OF_FILE) {
        std::cout << "Token: ";
        switch (tok) {
            case Token::NUMBER:
                std::cout << "NUMBER("<<static_cast<char>(39) << lexer.getText()<<static_cast<char>(39) << ")";
                break;
            case Token::AND_OPERATOR:
            std::cout << "AND OPERATOR("<<static_cast<char>(39) << lexer.getText()<<static_cast<char>(39) << ")";
                break;
            case Token::ASSIGN_OPERATOR:
            std::cout << "ASSIGN OPERATOR("<<static_cast<char>(39) << lexer.getText()<<static_cast<char>(39) << ")";
                break;
            case Token::COMA:
            std::cout << "COMA("<<static_cast<char>(39) << lexer.getText()<<static_cast<char>(39) << ")";
                break;
            case Token::DIVISION_OPERATOR:
            std::cout << "DIVISION OPERATOR("<<static_cast<char>(39) << lexer.getText()<<static_cast<char>(39) << ")";
                break;
            case Token::EQUAL_OPERATOR:
            std::cout << "EQUAL OPERATOR("<<static_cast<char>(39) << lexer.getText()<<static_cast<char>(39) << ")";
                break;
            case Token::GREATER_EQUAL_OPERATOR:
             std::cout << "GREATER_EQUAL OPERATOR("<<static_cast<char>(39) << lexer.getText()<<static_cast<char>(39) << ")";
                break;
            case Token::GREATER_OPERATOR:
             std::cout << "GREATER OPERATOR("<<static_cast<char>(39) << lexer.getText()<<static_cast<char>(39) << ")";
                break;
            case Token::IDENTIFIER:
             std::cout << "IDENTIFIER("<<static_cast<char>(39) << lexer.getText()<<static_cast<char>(39) << ")";
                break;
            case Token::Keyword_else:
             std::cout << "KEYWORD_ELSE("<<static_cast<char>(39) << lexer.getText()<<static_cast<char>(39) << ")";
                break;
            case Token::Keyword_if:
             std::cout << "KEYWORD_IF("<<static_cast<char>(39) << lexer.getText()<<static_cast<char>(39) << ")";
                break;
            case Token::Keyword_int:
             std::cout << "KEYWORD_INT("<<static_cast<char>(39) << lexer.getText()<<static_cast<char>(39) << ")";
                break;
            case Token::Keyword_print:
             std::cout << "KEYWORD PRINT("<<static_cast<char>(39) << lexer.getText()<<static_cast<char>(39) << ")";
                break;
            case Token::Keyword_while:
             std::cout << "KEYRWORD WHILE("<<static_cast<char>(39) << lexer.getText()<<static_cast<char>(39) << ")";
                break;
            case Token::LEFT_KEY:
             std::cout << "LEFT KEY("<<static_cast<char>(39) << lexer.getText()<<static_cast<char>(39) << ")";
                break;
            case Token::LEFT_PAR:
             std::cout << "LEFT PARENTHESIS("<<static_cast<char>(39) << lexer.getText()<<static_cast<char>(39) << ")";
                break;
            case Token::LESS_EQUAL_OPERATOR:
             std::cout << "LESS EQUAL OPERATOR("<<static_cast<char>(39) << lexer.getText()<<static_cast<char>(39) << ")";
                break;
            case Token::LESS_OPERATOR:
             std::cout << "LESS THAN OPERATOR("<<static_cast<char>(39) << lexer.getText()<<static_cast<char>(39) << ")";
                break;
            case Token::MODULE_OPERATOR:
             std::cout << "MODULE OPERATOR("<<static_cast<char>(39) << lexer.getText()<<static_cast<char>(39) << ")";
                break;
            case Token::MULTIPLICATION_OPERATOR:
             std::cout << "MULTIPLICATION OPERATOR("<<static_cast<char>(39) << lexer.getText()<<static_cast<char>(39) << ")";
                break;
            case Token::NOT_OPERATOR:
                std::cout << "NOT OPERATOR("<<static_cast<char>(39) << lexer.getText()<<static_cast<char>(39) << ")";
                break;
            case Token::NOT_EQUAL_OPERATOR:
                std::cout << "NOT EQUAL OPERATOR("<<static_cast<char>(39) << lexer.getText()<<static_cast<char>(39) << ")";
                break;
            case Token::OR_OPERATOR:
             std::cout << "OR OPERATOR("<<static_cast<char>(39) << lexer.getText()<<static_cast<char>(39) << ")";
                break;
            case Token::RIGHT_KEY:
            std::cout << "RIGHT KEY("<<static_cast<char>(39) << lexer.getText()<<static_cast<char>(39) << ")";
                break;
            case Token::RIGHT_PAR:
            std::cout << "RIGHT PARENTHESIS("<<static_cast<char>(39) << lexer.getText()<<static_cast<char>(39) << ")";
                break;
            case Token::SEMICOLON:
            std::cout << "SEMICOLON("<<static_cast<char>(39) << lexer.getText()<<static_cast<char>(39) << ")";
                break;
            case Token::SUBTRACTION_OPERATOR:
            std::cout << "SUBTRACTION_OPERATOR("<<static_cast<char>(39) << lexer.getText()<<static_cast<char>(39) << ")";
                break;
            case Token::SUM_OPERATOR:
            std::cout << "SUM OPERATOR("<<static_cast<char>(39) << lexer.getText()<<static_cast<char>(39) << ")";
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