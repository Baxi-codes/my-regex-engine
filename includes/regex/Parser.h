#ifndef PARSER_H
#define PARSER_H

#include <string>
#include "Lexer.h"
#include "AST.h"

class Parser {
private:
  Lexer lexer;
  Token currentToken;
  void eat(TokenType type);
  ASTNode* R();
  ASTNode* R_prime();
  ASTNode* T();
  ASTNode* T_prime();
  ASTNode* F();
  ASTNode* F_prime();
  ASTNode* A();

public:
  Parser(const std::string& input);
  ASTNode* parse();
};

#endif // PARSER_H