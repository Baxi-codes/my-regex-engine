#include "regex/AST.h"
#include "regex/Lexer.h"
#include <iostream>

void UnionASTNode::dump() {
  std::cout << "Union(";
  LHS->dump();
  std::cout << ", ";
  RHS->dump();
  std::cout << ")";
}

void ConcatASTNode::dump() {
  std::cout << "Concatenation(";
  LHS->dump();
  std::cout << ", ";
  RHS->dump();
  std::cout << ")";
}

void KleeneStarASTNode::dump() {
  std::cout << "KleeneStar(";
  operand->dump();
  std::cout << ")";
}

void SymbolASTNode::dump() { std::cout << "Symbol(" << symbol.lexeme << ")"; }
