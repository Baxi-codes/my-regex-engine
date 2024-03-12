#include "regex/Parser.h"

Parser::Parser(const std::string &input)
    : lexer(input), currentToken({TOKEN_EOF, std::string("INVALID")}) {}

void Parser::eat(TokenType type) {
  if (currentToken.type == type) {
    currentToken = lexer.getNextToken();
  } else {
    // Handle error: Unexpected token
    std::cerr << "Error: Unexpected token\n";
    switch (currentToken.type) {
    case TOKEN_SYMBOL:
      std::cerr << "TOKEN_SYMBOL: ";
      break;
    case TOKEN_UNION:
      std::cerr << "TOKEN_UNION: ";
      break;
    case TOKEN_CONCATENATION:
      std::cerr << "TOKEN_CONCATENATION: ";
      break;
    case TOKEN_KLEENE_STAR:
      std::cerr << "TOKEN_KLEENE_STAR: ";
      break;
    case TOKEN_LPAREN:
      std::cerr << "TOKEN_LPAREN: ";
      break;
    case TOKEN_RPAREN:
      std::cerr << "TOKEN_RPAREN: ";
      break;
    }
    std::cerr << currentToken.lexeme << std::endl;
    exit(1);
  }
}

ASTNode *Parser::parse() {
  currentToken = lexer.getNextToken(); // Initialize currentToken
  return R();
}

ASTNode *Parser::R() {
  ASTNode *LHS = T();
  ASTNode *RHS = R_prime();
  if (!LHS) {
    std::cerr << "This shouldn't happen in R\n";
    return nullptr;
  }
  if (!RHS) {
    return LHS;
  }
  return new UnionASTNode(LHS, RHS);
}

ASTNode *Parser::R_prime() {
  if (currentToken.type == TOKEN_UNION) {
    eat(TOKEN_UNION);
    return R();
  } else {
    if (currentToken.type == TOKEN_RPAREN || currentToken.type == TOKEN_EOF) {
      return nullptr;
    } else {
      std::cerr << "Unexpected token in R_prime: " << currentToken.lexeme
                << std::endl;
      return nullptr;
    }
  }
}

ASTNode *Parser::T() {
  ASTNode *LHS = F();
  ASTNode *RHS = T_prime();
  if (!LHS) {
    std::cerr << "This shouldn't happen in T\n";
    return nullptr;
  }
  if (!RHS) {
    return LHS;
  }
  return new ConcatASTNode(LHS, RHS);
}

ASTNode *Parser::T_prime() {
  if (currentToken.type == TOKEN_SYMBOL) {
    return T();
  } else if (currentToken.type == TOKEN_LPAREN) {
    return T();
  } else {
    if (currentToken.type == TOKEN_RPAREN || currentToken.type == TOKEN_UNION ||
        currentToken.type == TOKEN_EOF) {
      return nullptr;
    } else {
      std::cerr << "Unexpected token in T_prime: " << currentToken.lexeme
                << std::endl;
      return nullptr;
    }
  }
}

ASTNode *Parser::F() {
  ASTNode *LHS = A();
  bool RHS = F_prime();
  if (!LHS) {
    std::cerr << "This shouldn't happen in F\n";
    return nullptr;
  }
  if (!RHS) {
    return LHS;
  }
  return new KleeneStarASTNode(LHS);
}

bool Parser::F_prime() {
  if (currentToken.type == TOKEN_KLEENE_STAR) {
    eat(TOKEN_KLEENE_STAR);
    return true;
  }
  if (currentToken.type == TOKEN_SYMBOL || currentToken.type == TOKEN_LPAREN ||
      currentToken.type == TOKEN_RPAREN || currentToken.type == TOKEN_UNION ||
      currentToken.type == TOKEN_EOF) {
    return false;
  } else {
    std::cerr << "Unexpected token in F_prime: " << currentToken.lexeme
              << std::endl;
    return false;
  }
}

ASTNode *Parser::A() {
  if (currentToken.type == TOKEN_SYMBOL) {
    ASTNode *node = new SymbolASTNode(currentToken);
    eat(TOKEN_SYMBOL);
    return node;
  } else if (currentToken.type == TOKEN_LPAREN) {
    eat(TOKEN_LPAREN);
    ASTNode *node = R();
    eat(TOKEN_RPAREN);
    return node;
  } else {
    std::cerr << "Unexpected token in A: " << currentToken.lexeme << std::endl;
    return nullptr;
  }
}