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

ASTNode* UnionASTNode::getLHS() {
  return LHS;
}

ASTNode* UnionASTNode::getRHS() {
  return RHS;
}

void ConcatASTNode::dump() {
  std::cout << "Concatenation(";
  LHS->dump();
  std::cout << ", ";
  RHS->dump();
  std::cout << ")";
}

ASTNode* ConcatASTNode::getLHS() {
  return LHS;
}

ASTNode* ConcatASTNode::getRHS() {
  return RHS;
}

void KleeneStarASTNode::dump() {
  std::cout << "KleeneStar(";
  operand->dump();
  std::cout << ")";
}

ASTNode* KleeneStarASTNode::getOperand() {
  return operand;
}

void SymbolASTNode::dump() { std::cout << "Symbol(" << symbol.lexeme << ")"; }

std::string SymbolASTNode::getSymbol() {
  return std::string(symbol.lexeme);
}

bool nullable(ASTNode *n) {
  if (auto symAST = dynamic_cast<SymbolASTNode *>(n)) {
    if (symAST->getSymbol() == "null")
      return true;
    return false;
  } else if (auto unionAST = dynamic_cast<UnionASTNode *>(n)) {
    return nullable(unionAST->getLHS()) || nullable(unionAST->getRHS());
  } else if (auto concatAST = dynamic_cast<ConcatASTNode *>(n)) {
    return nullable(concatAST->getLHS()) && nullable(concatAST->getRHS());
  } else if (auto kleeneAST = dynamic_cast<KleeneStarASTNode *>(n)) {
    return true;
  } else {
    fprintf(stderr, "Unknown AST type :(\n");
    return false;
  }
}
