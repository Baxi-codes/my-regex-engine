#ifndef DFA_H
#define DFA_H

#include "DFA/State.h"
#include <map>
#include <string>
#include <utility>
#include <vector>

class DFA {
  std::vector<State *> states;
  std::vector<char> alphabet;
  State *initial_state;
  std::map<State *, bool> is_final;
  std::map<std::pair<State *, char>, State *> transition;

public:
  DFA(std::vector<State *> Q, std::vector<char> sigma, State *q0,
      std::map<State *, bool> A,
      std::map<std::pair<State *, char>, State *> delta);
  
  bool match(std::string input);
  ~DFA();
};

#endif // DFA_H