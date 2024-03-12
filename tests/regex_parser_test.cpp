#include "regex/AST.h"
#include "regex/Parser.h"
#include <iostream>

int main(int argc, char const *argv[]) {
  if (argc != 2) {
    printf("1 argument required\n");
    return 0;
  }
  std::string input(argv[1]);
  Parser myParser(input);
  ASTNode *AST = myParser.parse();
  AST->dump();
  printf("\n");
  return 0;
}