#include "regex/AST.h"
#include "regex/Lexer.h"
#include <iostream>

int main(int argc, char const *argv[])
{
  if (argc != 2) {
    printf("1 argument required\n");
    return 0;
  }
  std::string input(argv[1]);
  Lexer myLexer(input);
  Token curTok = myLexer.getNextToken();
  while (curTok.type != TOKEN_EOF) {
    switch(curTok.type){
      case TOKEN_SYMBOL:
        printf("TOKEN_SYMBOL: ");
        break;
      case TOKEN_UNION:
        printf("TOKEN_UNION: ");
        break;
      case TOKEN_CONCATENATION:
        printf("TOKEN_CONCATENATION: ");
        break;
      case TOKEN_KLEENE_STAR:
        printf("TOKEN_KLEENE_STAR: ");
        break;
      case TOKEN_LPAREN:
        printf("TOKEN_LPAREN: ");
        break;
      case TOKEN_RPAREN:
        printf("TOKEN_RPAREN: ");
        break;
    }
    std::cout << curTok.lexeme << std::endl;
    curTok = myLexer.getNextToken();
  }
  return 0;
}