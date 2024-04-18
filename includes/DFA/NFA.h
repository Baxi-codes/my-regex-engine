#ifndef NFA_H
#define NFA_H

#include "DFA/State.h"
#include <map>
#include <string>
#include <utility>
#include <vector>

class NFA {
  std::vector<State *> states;
  std::vector<char> alphabet;
  State *initial_state;
  std::map<State *, bool> is_final;
  std::map<std::pair<State *, char>, std::vector<State *>> transition;

public:
  NFA(std::vector<State *> Q, std::vector<char> sigma, State *q0,
      std::map<State *, bool> A,
      std::map<std::pair<State *, char>, std::vector<State *>> delta);
  NFA(ASTNode* regex);
  bool match(std::string input);
  ~NFA();
};

NFA* NFAUnion(NFA* M1, NFA* M2) {
  std::vector<State *> states = M1.states;
  for (auto state : M2.states) {
    states.append(state);
  }
  State* q0 = new State();
  states.append(q0);

}

#endif // NFA_H