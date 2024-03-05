#ifndef PARSER_H
#define PARSER_H

#include <string>
#include "lexer.h"
#include "ast.h"

class Parser {
private:
    Lexer lexer;
    Token currentToken;

    void eat(TokenType type);
    ASTNode* factor();
    ASTNode* term();
    ASTNode* expr();

public:
    Parser(const std::string& input);

    ASTNode* parse();
};

#endif // PARSER_H