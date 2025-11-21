#include "Lexer.hpp"
#include <iostream>
#include <stdexcept>
enum class State
{
    Q0,
    NUMBER_Q1,
    IDENTIFIER_Q1,
    ESPACIO_Q1,
    NOT_EQUAL_Q1, 
    AND_Q1, 
    LESS_EQUAL_Q1, 
    GREATER_EQUAL_Q1, 
    MULTIPLICATION_Q1,
    DIVISION_Q1, 
    SUBTRACTION_Q1, 
    SUM_Q1,
    MODULE_Q1, 
    NOT__Q1, 
    LESS__Q1,
    GREATER_Q1, 
    OR_Q1, 
    ASSIGN_Q1, 
    SEMICOLON_Q1, 
    COMA_Q1,
    LEFT_PAR_Q1,
    RIGHT_PAR_Q1, 
    LEFT_KEY_Q1, 
    RIGHT_KEY_Q1,
    COMMENT_Q1, 
    END_OF_FILE,
    ERROR
};

Token Lexer::nextToken()
{
    int i=1;
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
                if(currentChar=='\n'){i++;}
                currentChar = in.get(); 
                state = State::ESPACIO_Q1;
            }
            else if (currentChar=='+')
            {
                text += static_cast<char>(currentChar);
                currentChar = in.get();
                state = State::SUM_Q1;
            }
            else if (currentChar=='*')
            {
                text += static_cast<char>(currentChar);
                currentChar = in.get();
                state = State::MULTIPLICATION_Q1;
            }
            else if (currentChar=='%')
            {
                text += static_cast<char>(currentChar);
                currentChar = in.get();
                state = State::MODULE_Q1;
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
                state = State::RIGHT_PAR_Q1;
            }
            else if (currentChar=='{')
            {
                text += static_cast<char>(currentChar);
                currentChar = in.get();
                state = State::LEFT_KEY_Q1;
            }
            else if (currentChar=='}')
            {
                text += static_cast<char>(currentChar);
                currentChar = in.get();
                state = State::RIGHT_KEY_Q1;
            }
            else if (currentChar=='-')
            {
                text += static_cast<char>(currentChar);
                currentChar = in.get();
                state = State::SUBTRACTION_Q1;
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
                state = State::NOT__Q1;
            }
            else if (currentChar==';')
            {
                text += static_cast<char>(currentChar);
                currentChar = in.get();
                state = State::SEMICOLON_Q1;
            }
            else if (currentChar=='&')
            {
                text += static_cast<char>(currentChar);
                currentChar = in.get();
                state = State::AND_Q1;
            }
            else if (currentChar=='<')
            {
                text += static_cast<char>(currentChar);
                currentChar = in.get();
                state = State::LESS__Q1;
            }
            else if (currentChar=='|')
            {
                text += static_cast<char>(currentChar);
                currentChar = in.get();
                state = State::OR_Q1;
            }
            else if (currentChar=='=')
            {
                text += static_cast<char>(currentChar);
                currentChar = in.get();
                state = State::ASSIGN_Q1;
            }
            else if (currentChar=='>')
            {
                text += static_cast<char>(currentChar);
                currentChar = in.get();
                state = State::GREATER_Q1;
            }
            else if (isdigit(currentChar))
            {
                text += static_cast<char>(currentChar);
                currentChar = in.get();
                state = State::NUMBER_Q1;
            }
            else if((currentChar>='a'&&currentChar<='z')||(currentChar>='A'&&currentChar<='Z')||
                    currentChar=='_'){
                text += static_cast<char>(currentChar);
                currentChar = in.get();
                state = State::IDENTIFIER_Q1;
            }
            else{
                state=State::ERROR;
                text += static_cast<char>(currentChar);
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
        case State::IDENTIFIER_Q1:
        if((currentChar>='a'&&currentChar<='z')||(currentChar>='A'&&currentChar<='Z')||
                currentChar=='_'||isdigit(currentChar)){
                text += static_cast<char>(currentChar);
                currentChar = in.get();
            }else{
                if(text=="int"){return Token::Keyword_int;}
                if(text=="if"){return Token::Keyword_if;}
                if(text=="else"){return Token::Keyword_else;}
                if(text=="while"){return Token::Keyword_while;}
                if(text=="print"){return Token::Keyword_print;}
                state=State::Q0;
                return Token::IDENTIFIER;
            }
        break;
        case State::ESPACIO_Q1:
        if(isspace(currentChar)){
            currentChar=in.get();
        }else{
            state=State::Q0;
        }
        break;
        case State::NOT_EQUAL_Q1:
        currentChar = in.get();
        state=State::Q0;
        return Token::NOT_EQUAL_OPERATOR;
        break;
        case State::AND_Q1:
        if(currentChar=='&'){
            text += static_cast<char>(currentChar);
            currentChar = in.get();
            state = State::Q0;
            return Token::AND_OPERATOR;
        }else{
            state=State::ERROR;
        }
        break;
        case State::LESS_EQUAL_Q1:
        currentChar = in.get();
        state=State::Q0;
        return Token::LESS_EQUAL_OPERATOR;
        break;
        case State::GREATER_EQUAL_Q1:
        currentChar = in.get();
        state=State::Q0;
        return Token::GREATER_EQUAL_OPERATOR;
        break;
        case State::MULTIPLICATION_Q1:
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
        case State::SUBTRACTION_Q1:
        if(isdigit(currentChar)){
            text += currentChar;
            currentChar=in.get();
            state=State::NUMBER_Q1;
        }else{
            state=State::Q0;
            return Token::SUBTRACTION_OPERATOR;
        }
        break;
        case State::SUM_Q1:
        state=State::Q0;
        return Token::SUM_OPERATOR;
        break;
        case State::MODULE_Q1:
        state=State::Q0;
        return Token::MODULE_OPERATOR;
        break;
        case State::NOT__Q1:
        if(currentChar == '='){
        text += static_cast<char>(currentChar); 
        state = State::NOT_EQUAL_Q1;
    } else {
        state = State::Q0;
        return Token::NOT_OPERATOR;
    }
        break; 
        case State::LESS__Q1:
        if(currentChar=='='){
            text += static_cast<char>(currentChar); 
            state = State::LESS_EQUAL_Q1;
        }else{
            state=State::Q0;
            return Token::LESS_OPERATOR;
        }

        break;
        case State::GREATER_Q1:
        if(currentChar=='='){
            text += static_cast<char>(currentChar); 
            state = State::GREATER_EQUAL_Q1;
        }
        else{
            state=State::Q0;
            return Token::GREATER_OPERATOR;
        }
        break; 
        case State::OR_Q1:
        if(currentChar=='|'){
            text += static_cast<char>(currentChar);
            currentChar = in.get();
            state = State::Q0;
            return Token::OR_OPERATOR;
        }else{
            state=State::ERROR;
        }
        break; 
        case State::ASSIGN_Q1:
        if(currentChar=='='){
            text += static_cast<char>(currentChar);
            currentChar = in.get();
            state = State::Q0;
            return Token::EQUAL_OPERATOR;
        }else{
            state=State::Q0;
            return Token::ASSIGN_OPERATOR;
        }
        break; 
    case State::SEMICOLON_Q1:
     state=State::Q0;
    return Token::SEMICOLON;
    break; 
    case State::COMA_Q1:
     state=State::Q0;
    return Token::COMA;
    break;
    case State::LEFT_PAR_Q1:

    state=State::Q0;
    return Token::LEFT_PAR;
    break;
    case State::RIGHT_PAR_Q1: 

     state=State::Q0;
    return Token::RIGHT_PAR;
    break;
    case State::LEFT_KEY_Q1: 

     state=State::Q0;
    return Token::LEFT_KEY;
    break;
    case State::RIGHT_KEY_Q1:

     state=State::Q0;
    return Token::RIGHT_KEY;
    break;
    case State::COMMENT_Q1:
    if (currentChar == '\n' || currentChar == '\r'){
        currentChar=in.get();
        state=State::Q0;
    }
    else if(currentChar==EOF){
        state=State::END_OF_FILE;
    }
    else{
        currentChar=in.get();
    }
    break;
        case State::END_OF_FILE:
            return Token::END_OF_FILE;
            break;
        case State::ERROR:
        std::string error_msg = "Error léxico: Lexema inválido '";
        error_msg += text;
        error_msg += "' encontrado.";
        throw std::runtime_error(error_msg);
        break;
        }
    };
}