#include "Lexer.hpp"
#include <iostream>

class Parser{
    private:
    Lexer lexer;
    Token currentToken;
    void statement();
    void varDecl();
    void assignment();
    void ifStmt();
    void whileStmt();
    void printStmt();
    void block();
    void expression();
    void logicalOr();
    void logicalAnd();
    void equality();
    void comparison();
    void term();
    void factor();
    void unary();
    void primary();
    public:
    Parser(Lexer& lexer_,Token currentToken_):lexer(lexer_),currentToken(currentToken_){}
    void Parse();
};


void Parser::Parse(){
    std::cout<<"PARSER\n";
    while((currentToken=lexer.nextToken())!=Token::END_OF_FILE){
        statement();
    }
    if(currentToken!=Token::END_OF_FILE){
        std::string error_msg = "Error sintactico: Lexema inválido '";
        error_msg += lexer.getText();
        error_msg += "' encontrado.";
        throw std::runtime_error(error_msg);
    }
}
void Parser::statement(){
    if(currentToken==Token::Keyword_int){
        varDecl();
    }else if(currentToken==Token::IDENTIFIER){
        assignment();
    }else if(currentToken==Token::Keyword_if){
        ifStmt();
    }else if(currentToken==Token::Keyword_while){
        whileStmt();
    }else if(currentToken==Token::Keyword_print){
        printStmt();
    }else if(currentToken==Token::LEFT_KEY){
        block();
    }else{
        std::string c=lexer.getText();
        throw std::runtime_error("Error sintáctico de statement\nENCONTRADO:"+c);
    }
}
void Parser::varDecl(){
    currentToken=lexer.nextToken();
    if(currentToken==Token::IDENTIFIER){
        currentToken=lexer.nextToken();
        if(currentToken==Token::ASSIGN_OPERATOR){
            currentToken=lexer.nextToken();
            expression();
        }
        if(currentToken==Token::SEMICOLON){
        }
        else{
            std::string c=lexer.getText();
            throw std::runtime_error("Error sintáctico de declaracion de variable: Se esperaba ; \nENCONTRADO:"+c);
        }
    }
    else{
        std::string c=lexer.getText();
            throw std::runtime_error("Error sintáctico de declaracion de variable: Se esperaba Identifier después de 'int'\nENCONTRADO: "+c);
        }
}
void Parser::assignment(){
    currentToken=lexer.nextToken();
    if(currentToken==Token::ASSIGN_OPERATOR){
        currentToken=lexer.nextToken();
        expression();
        if(currentToken!=Token::SEMICOLON){
            std::string c=lexer.getText();
            throw std::runtime_error("Error sintáctico de asignacion: Se esperaba ; \nENCONTRADO: "+c);
        }
    }else{
        std::string c=lexer.getText();
        throw std::runtime_error("Error sintáctico de asignacion: Se esperaba = \nENCONTRADO: "+c);
    }
}
void Parser::ifStmt(){
    currentToken=lexer.nextToken();
    if(currentToken==Token::LEFT_PAR){
        currentToken=lexer.nextToken();
        expression();
        if(currentToken==Token::RIGHT_PAR){
            currentToken=lexer.nextToken();
            statement();
            currentToken=lexer.nextToken();
            if(currentToken==Token::Keyword_else){
                currentToken=lexer.nextToken();
                statement();
            }
        }else{
            std::string c=lexer.getText();
            throw std::runtime_error("Error sintáctico de statement IF: Se esperaba ) \nENCONTRADO: "+c);
        }
    }else{
        std::string c=lexer.getText();
        throw std::runtime_error("Error sintáctico de statement IF: Se esperaba ( \nENCONTRADO: "+c);
    }
}
void Parser::whileStmt(){
    currentToken=lexer.nextToken();
    if(currentToken==Token::LEFT_PAR){
        currentToken=lexer.nextToken();
        expression();
        if(currentToken==Token::RIGHT_PAR){
            currentToken=lexer.nextToken();
            statement();
        }else{
            std::string c=lexer.getText();
            throw std::runtime_error("Error sintáctico de statement WHILE: Se esperaba ) luego de expression \nENCONTRADO: "+c);
        }
    }else{
        std::string c=lexer.getText();
        throw std::runtime_error("Error sintáctico de statement WHILE: Se esperaba ( antes de expression\nENCONTRADO: "+c);
    }
}
void Parser::printStmt(){
    currentToken=lexer.nextToken();
    if(currentToken==Token::LEFT_PAR){
        currentToken=lexer.nextToken();
        expression();
        if(currentToken==Token::RIGHT_PAR){
            currentToken=lexer.nextToken();
            if(currentToken==Token::SEMICOLON){
            }else{
                std::string c=lexer.getText();
                throw std::runtime_error("Error sintáctico de statement PRINT: Se esperaba ; luego de expression \nENCONTRADO: "+c);
            }
        }else{
            std::string c=lexer.getText();
            throw std::runtime_error("Error sintáctico de statement PRINT: Se esperaba ) luego de expression \nENCONTRADO: "+c);
        }
    }else{
        std::string c=lexer.getText();
        throw std::runtime_error("Error sintáctico de statement PRINT: Se esperaba ( antes de expression\nENCONTRADO: "+c);
    }
}
void Parser::block(){
    bool a=true;
    while (a) {
        currentToken=lexer.nextToken();
        if(currentToken != Token::RIGHT_KEY && currentToken != Token::END_OF_FILE){
            statement();
        }else{
            a=false;
        }
        
    }
    if (currentToken == Token::RIGHT_KEY) {
    } else if (currentToken == Token::END_OF_FILE) {
        throw std::runtime_error("Error sintactico: Fin de archivo alcanzado antes de encontrar '}' para cerrar el bloque.");
    } else {
        std::string c=lexer.getText();
        throw std::runtime_error("Error sintactico: Se esperaba '}' para cerrar el bloque\nENCONTRADO: "+c);
    }
}
void Parser::expression(){
    //expression → logicalOr
    logicalOr();
}
void Parser::logicalOr(){
    //logicalOr → logicalAnd ("||" logicalAnd)*
    logicalAnd();
    while (currentToken == Token::OR_OPERATOR) {
        currentToken=lexer.nextToken();
        logicalAnd(); 
    }
}
void Parser::logicalAnd(){
    //logicalAnd → equality ("&&" equality)*
    equality();
    while (currentToken == Token::AND_OPERATOR) {
        currentToken=lexer.nextToken();
        equality(); 
    }
}
void Parser::equality(){
    // equality → comparison (("==" | "!=") comparison)*
    comparison();
    while (currentToken==Token::EQUAL_OPERATOR||currentToken==Token::NOT_EQUAL_OPERATOR)
    {
        currentToken=lexer.nextToken();
        comparison();
    }
    
}
void Parser::comparison(){
    //comparison → term (("<" | ">" | "<=" | ">=") term)*
    term();
    while (currentToken==Token::LESS_OPERATOR||currentToken==Token::GREATER_OPERATOR||currentToken==Token::LESS_EQUAL_OPERATOR
        ||currentToken==Token::GREATER_EQUAL_OPERATOR)
    {
        currentToken=lexer.nextToken();
        term();
    }
    
}
void Parser::term(){
    //term → factor (("+" | "-") factor)*
    factor();
    while (currentToken==Token::SUM_OPERATOR||currentToken==Token::SUBTRACTION_OPERATOR)
    {
        currentToken=lexer.nextToken();
        factor();
    }
    
}
void Parser::factor(){
    //factor → unary (("*" | "/" | "%") unary)*
    unary();
    while (currentToken==Token::MULTIPLICATION_OPERATOR||currentToken==Token::DIVISION_OPERATOR
        ||currentToken==Token::MODULE_OPERATOR)
    {
        currentToken=lexer.nextToken();
        unary();
    }
    
}
void Parser::unary(){
    //unary → ("!" | "-") unary| primary
    if(currentToken==Token::NOT_OPERATOR||currentToken==Token::SUBTRACTION_OPERATOR){
        currentToken=lexer.nextToken();
        unary();
    }
    else if(currentToken==Token::IDENTIFIER||currentToken==Token::NUMBER||currentToken==Token::LEFT_PAR){
        primary();
    }
    else{
        std::string c=lexer.getText();
        throw std::runtime_error("Error sintactico: Se esperaba '!' '-' '('\nENCONTRADO: "+c);
    }
}
void Parser::primary(){
    //primary → INTEGER | IDENTIFIER | "(" expression ")"
    if(currentToken == Token::NUMBER){
        currentToken = lexer.nextToken(); 
    } 
    else if(currentToken == Token::IDENTIFIER){
        currentToken = lexer.nextToken(); 
    } 
    else if(currentToken == Token::LEFT_PAR){
        currentToken = lexer.nextToken();
        expression(); 
        if(currentToken != Token::RIGHT_PAR){
            std::string c=lexer.getText();
            throw std::runtime_error("Error sintactico: Se esperaba ')' para cerrar la expresión.\nENCONTRADO: "+c);
        }
        currentToken = lexer.nextToken(); 
    }
    else {
        std::string c=lexer.getText();
        throw std::runtime_error("Error sintactico: Se esperaba una expresión primaria (número, identificador o '(').\nENCONTRADO: "+c);
    }
}