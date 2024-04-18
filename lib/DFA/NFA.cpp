#include "DFA/NFA.h"
#include <iostream>
#include <map>
#include <string>
#include <utility>
#include <vector>

NFA::NFA(std::vector<State *> Q, std::vector<char> sigma, State *q0,
         std::map<State *, bool> A,
         std::map<std::pair<State *, char>, std::vector<State *>> delta)
    : states(Q), alphabet(sigma), initial_state(q0), is_final(A),
      transition(delta) {}

NFA::NFA(ASTNode* root) {
  // Initialize attributes
  states = {};
  alphabet = {};
  initial_state = nullptr;
  is_final = {};
  transition = {};

  stack<ASTNode *> expressionStack;
  expressionStack.push(root);
  while(!expressionStack.empty()) {
    ASTNode *current = expressionStack.top();
    expressionStack.pop();
    if (StartASTNode* startNode = dynamic_cast<StartASTNode*>(current)) {
      // do something
    } else if (UnionASTNode* unionNode = dynamic_cast<UnionASTNode*>(current)) {
      
    } else if (ConcatASTNode* concatNode = dynamic_cast<ConcatASTNode*>(current)) {
      // do something
    } else if (KleeneStarASTNode* kleeneNode = dynamic_cast<KleeneStarASTNode*>(current)) {
      // do something
    } else if (SymbolASTNode* symbolNode = dynamic_cast<SymbolASTNode*>(current)) {
      // do something
    } else {
      printf("Unreachable\n");
      exit(1);
    }
  }
}

bool NFA::match(std::string input) {
  // TODO: implement match
  return true;
}