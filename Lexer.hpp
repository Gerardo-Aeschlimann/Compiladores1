#pragma once
#include <istream>
#include <string>

enum class Token {
    Keyword_int,
    Keyword_if,
    Keyword_else,
    Keyword_while,
    Keyword_print,
    IDENTIFIER,
    NUMBER,
    SUM_OPERATOR,
    SUBTRACTION_OPERATOR,
    MULTIPLICATION_OPERATOR,
    DIVISION_OPERATOR,
    MODULE_OPERATOR,
    EQUAL_OPERATOR,
    NOT_EQUAL_OPERATOR,
    LESS_OPERATOR,
    GREATER_OPERATOR,
    LESS_EQUAL_OPERATOR,
    GREATER_EQUAL_OPERATOR,
    AND_OPERATOR,
    OR_OPERATOR,
    NOT_OPERATOR,
    ASSIGN_OPERATOR,
    SEMICOLON,
    COMA,
    LEFT_PAR,
    RIGHT_PAR,
    LEFT_KEY,
    RIGHT_KEY,
    END_OF_FILE,
    ERROR
};

class Lexer {
public:
    Lexer(std::istream &in_) : in(in_) {
        currentChar = in.get();
    }

    std::string getText() const { return text; }
    Token nextToken();

private:
    std::istream &in;
    std::string text;
    int currentChar;
};