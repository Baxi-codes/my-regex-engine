#include "regex/Lexer.h"
#include <cctype>
#include <iostream>

Lexer::Lexer(const std::string &input) : input(input), currentPos(0) {}

char Lexer::peek() const {
  if (currentPos < input.size()) {
    return input[currentPos];
  } else {
    return '\0'; // End of input
  }
}

char Lexer::advance() {
  if (currentPos < input.size()) {
    return input[currentPos++];
  } else {
    return '\0'; // End of input
  }
}

void Lexer::skipWhitespace() {
  while (isspace(peek())) {
    advance();
  }
}

Token Lexer::getNextToken() {
  skipWhitespace();

  if (peek() == '\0') {
    return {TOKEN_EOF, ""};
  }

  switch (peek()) {
  case '+':
    advance();
    return {TOKEN_UNION, "+"};
  case '*':
    advance();
    return {TOKEN_KLEENE_STAR, "*"};
  case '(':
    advance();
    return {TOKEN_LPAREN, "("};
  case ')':
    advance();
    return {TOKEN_RPAREN, ")"};
  default:
    std::string symbol;
    if (peek() == '\\') {
      advance();
    }
    symbol += peek();
    advance();
    return {TOKEN_SYMBOL, symbol};
  }
}
