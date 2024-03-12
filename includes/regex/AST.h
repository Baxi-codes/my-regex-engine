#ifndef AST_H
#define AST_H

#include "regex/Lexer.h"
#include <iostream>

class ASTNode {
public:
  virtual void dump() = 0;
};

class UnionASTNode : public ASTNode {
  ASTNode *LHS, *RHS;

public:
  UnionASTNode(ASTNode *l, ASTNode *r) : LHS(l), RHS(r) {}
  void dump();
};

class ConcatASTNode : public ASTNode {
  ASTNode *LHS, *RHS;

public:
  ConcatASTNode(ASTNode *l, ASTNode *r) : LHS(l), RHS(r) {}
  void dump();
};

class KleeneStarASTNode : public ASTNode {
  ASTNode *operand;

public:
  KleeneStarASTNode(ASTNode *op) : operand(op) {}
  void dump();
};

class SymbolASTNode : public ASTNode {
  Token symbol;

public:
  SymbolASTNode(Token sym) : symbol(sym) {}
  void dump();
};

#endif // AST_H