#include "Lexer.hpp"
#include <cctype>

enum class State {
    Q0,
    END_OF_FILE_Q1,
    NUMBER_Q1,
    IDENTIFIER_Q1
};

void Lexer::skipWhitespace() {
    while (std::isspace(currentChar)) {
        currentChar = in.get();
    }
}

Token Lexer::nextToken() {
    text.clear();
    skipWhitespace();

    State state = State::Q0;

    while (true) {
        switch (state) {

        case State::Q0:
            if (currentChar == EOF)
                return Token::END_OF_FILE;

            if (std::isdigit(currentChar)) {
                text += static_cast<char>(currentChar);
                currentChar = in.get();
                state = State::NUMBER_Q1;
                break;
            }

            if (std::isalpha(currentChar)) {
                text += static_cast<char>(currentChar);
                currentChar = in.get();
                state = State::IDENTIFIER_Q1;
                break;
            }

            currentChar = in.get();
            break; 

        case State::NUMBER_Q1:
            if (!std::isdigit(currentChar)) {
                return Token::NUMBER;
            }
            text += static_cast<char>(currentChar);
            currentChar = in.get();
            break;

        case State::IDENTIFIER_Q1:
            if (!std::isalnum(currentChar) && currentChar != '_') {
                return Token::IDENTIFIER;
            }
            text += static_cast<char>(currentChar);
            currentChar = in.get();
            break;

        } 
    } 
}
