#include "Lexer.hpp"

enum class State
{
    Q0,
    END_OF_FILE_Q1,
    NUMBER_Q1,
    IDENTIFIER_Q1,
    IDENTIFIER_Q2,
    IDENTIFIER_Q3,
};

Token Lexer::nextToken()
{
    State state = State::Q0;

    while (true)
    {
        switch (state)
        {
        case State::Q0:
            if (currentChar == EOF)
                state = State::END_OF_FILE_Q1;

            else if (isdigit(currentChar))
            {
                text += static_cast<char>(currentChar);
                currentChar = in.get();
                state = State::NUMBER_Q1;
            }
            break;
        case State::NUMBER_Q1:
            if (!isdigit(currentChar))
            {
                text.clear();
                currentChar = in.get();
                state = State::Q0;
                return Token::NUMBER;
            }

            text += currentChar;
            currentChar = in.get();
        case State::END_OF_FILE_Q1:
            return Token::END_OF_FILE;
        }
    };
}