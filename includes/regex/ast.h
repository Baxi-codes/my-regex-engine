#ifndef AST_H
#define AST_H

#include <iostream>

class ASTNode {
public:
  ASTNode();
  virtual ~ASTNode();
  virtual void dump();
};

class UnionASTNode : ASTNode {
  ASTNode *LHS, *RHS;

public:
  UnionASTNode(ASTNode *l, ASTNode *r) : LHS(l), RHS(r) {}
  void dump();
};

class ConcatASTNode : ASTNode {
  ASTNode *LHS, *RHS;

public:
  ConcatASTNode(ASTNode *l, ASTNode *r) : LHS(l), RHS(r) {}
  void dump();
};

class KleeneStarASTNode : ASTNode {
  ASTNode *operand;

public:
  KleeneStarASTNode(ASTNode *op) : operand(op) {}
  void dump();
};

#endif // AST_H