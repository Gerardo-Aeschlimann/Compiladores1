#include "Lexer.hpp"
#include <iostream>
enum class State
{
    Q0,
    NUMBER_Q1,
    IDENTIFIER_Q2, 
    ESPACIO_Q3, 
    NOT_EQUAL_Q8, 
    AND_Q9, 
    LESS_EQUAL_Q10, 
    GREATER_EQUAL_Q11, 
    MULTIPLICATION_Q12,
    DIVISION_Q1, 
    SUBTRACTION_Q14, 
    SUM_Q15,
    MODULE_Q17, 
    NOT__Q18, 
    LESS__Q19,
    GREATER_Q20, 
    OR_Q21, 
    ASSIGN_Q22, 
    SEMICOLON_Q23, 
    COMA_Q24,
    AND_Q25, 
    LEFT_PAR_Q1,
    RIGHT_PAR_Q26, 
    LEFT_KEY_Q27, 
    RIGHT_KEY_Q28,
    COMMENT_Q1, 
    COMMENT_Q30, 
    END_OF_FILE 
};

Token Lexer::nextToken()
{
    text.clear();
    State state = State::Q0;
    while (true)
    {
        switch (state)
        {
        case State::Q0:
            if (currentChar == EOF)
                state = State::END_OF_FILE;
            else if(isspace(currentChar)){
                currentChar = in.get(); 
                state = State::ESPACIO_Q3;
            }
            else if (currentChar=='+')
            {
                text += static_cast<char>(currentChar);
                currentChar = in.get();
                state = State::SUM_Q15;
            }
            else if (currentChar=='*')
            {
                text += static_cast<char>(currentChar);
                currentChar = in.get();
                state = State::MULTIPLICATION_Q12;
            }
            else if (currentChar=='%')
            {
                text += static_cast<char>(currentChar);
                currentChar = in.get();
                state = State::MODULE_Q17;
            }
            else if (currentChar=='(')
            {
                text += static_cast<char>(currentChar);
                currentChar = in.get();
                state = State::LEFT_PAR_Q1;
            }
            else if (currentChar==')')
            {
                text += static_cast<char>(currentChar);
                currentChar = in.get();
                state = State::RIGHT_PAR_Q26;
            }
            else if (currentChar=='{')
            {
                text += static_cast<char>(currentChar);
                currentChar = in.get();
                state = State::LEFT_KEY_Q27;
            }
            else if (currentChar=='}')
            {
                text += static_cast<char>(currentChar);
                currentChar = in.get();
                state = State::RIGHT_KEY_Q28;
            }
            else if (currentChar=='-')
            {
                text += static_cast<char>(currentChar);
                currentChar = in.get();
                state = State::SUBTRACTION_Q14;
            }
            else if (currentChar=='/')
            {
                text += static_cast<char>(currentChar);
                currentChar = in.get();
                state = State::DIVISION_Q1;
            }
            else if (currentChar=='!')
            {
                text += static_cast<char>(currentChar);
                currentChar = in.get();
                state = State::NOT__Q18;
            }
            else if (isdigit(currentChar))
            {
                text += static_cast<char>(currentChar);
                currentChar = in.get();
                state = State::NUMBER_Q1;
            }
            else if(currentChar>'A'){
                
            }
            break;
        case State::NUMBER_Q1:
            if (!isdigit(currentChar))
            {
                state = State::Q0;
                return Token::NUMBER;
            }

            text += currentChar;
            currentChar = in.get();
        break;
        case State::IDENTIFIER_Q2:

        break;
        case State::ESPACIO_Q3:
        if(isspace(currentChar)){
            currentChar=in.get();
        }else{
            state=State::Q0;
        }
        break;
        case State::NOT_EQUAL_Q8:
        currentChar = in.get();
        state=State::Q0;
        return Token::NOT_EQUAL_OPERATOR;
        break;
        case State::AND_Q9:

        break;
        case State::LESS_EQUAL_Q10:

        break;
        case State::GREATER_EQUAL_Q11:

        break;
        case State::MULTIPLICATION_Q12:
        state=State::Q0;
        return Token::MULTIPLICATION_OPERATOR;
        break;
        case State::DIVISION_Q1:
        if(currentChar=='/'){
            text.clear();
            currentChar=in.get();
            state=State::COMMENT_Q1;
        }else{
            state=State::Q0;
            return Token::DIVISION_OPERATOR;
        }
        break;
        case State::SUBTRACTION_Q14:
        if(isdigit(currentChar)){
            text += currentChar;
            currentChar=in.get();
            state=State::NUMBER_Q1;
        }else{
            state=State::Q0;
            return Token::SUBTRACTION_OPERATOR;
        }
        break; 
        case State::SUM_Q15:
        state=State::Q0;
        return Token::SUM_OPERATOR;
        break;
        case State::MODULE_Q17:
        state=State::Q0;
        return Token::MODULE_OPERATOR;
        break;
        case State::NOT__Q18:
        if(currentChar == '='){
        text += static_cast<char>(currentChar); 
        state = State::NOT_EQUAL_Q8;
    } else {
        state = State::Q0;
        return Token::NOT_OPERATOR;
    }
        break; 
        case State::LESS__Q19:

        break;
        case State::GREATER_Q20:

        break; 
        case State::OR_Q21:

        break; 
        case State::ASSIGN_Q22:
        break; 
    case State::SEMICOLON_Q23:
    break; 
    case State::COMA_Q24:
    break;
    case State::AND_Q25: 
    break;
    case State::RIGHT_PAR_Q26: 
    break;
    case State::LEFT_KEY_Q27: 
    break;
    case State::RIGHT_KEY_Q28:
    break;
    case State::COMMENT_Q1: 
    if (currentChar == '\n' || currentChar == '\r'){
        currentChar=in.get();
        state=State::Q0;
    }
    else{
        std::cout<<"siguiente: "<<static_cast<char>(currentChar)<<"Text: "<<text<<std::endl;
        currentChar=in.get();
    }
    break;
    case State::COMMENT_Q30:
    break; 
        case State::END_OF_FILE:
            return Token::END_OF_FILE;
            break;
        default:
        return Token::ERROR;
        break;
        }
    };
}