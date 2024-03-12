#include "regex/AST.h"
#include "regex/Lexer.h"
#include <iostream>

int main(int argc, char const *argv[]) {
  Token a = {TOKEN_SYMBOL, std::string("a")};
  Token b = {TOKEN_SYMBOL, std::string("b")};
  Token c = {TOKEN_SYMBOL, std::string("c")};
  ASTNode *test = new UnionASTNode(
      new ConcatASTNode(new SymbolASTNode(a), new SymbolASTNode(b)),
      new KleeneStarASTNode(new SymbolASTNode(c)));
  test->dump();
  std::cout << std::endl;
  return 0;
}