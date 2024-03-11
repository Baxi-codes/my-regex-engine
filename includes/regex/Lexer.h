#ifndef LEXER_H
#define LEXER_H

#include <string>

enum TokenType {
    TOKEN_SYMBOL,
    TOKEN_UNION,
    TOKEN_CONCATENATION,
    TOKEN_KLEENE_STAR,
    TOKEN_LPAREN,
    TOKEN_RPAREN,
    TOKEN_EOF
};

struct Token {
    TokenType type;
    std::string lexeme;
};

class Lexer {
    std::string input;
    size_t currentPos;

public:
    Lexer(const std::string& input);
    char peek() const;
    char advance();
    void skipWhitespace();
    Token getNextToken();
};

#endif // LEXER_H