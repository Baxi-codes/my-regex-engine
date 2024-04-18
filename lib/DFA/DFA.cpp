#include "DFA/DFA.h"
#include <iostream>
#include <map>
#include <string>
#include <utility>
#include <vector>

DFA::DFA(std::vector<State *> Q, std::vector<char> sigma, State *q0,
         std::map<State *, bool> A,
         std::map<std::pair<State *, char>, State *> delta)
    : states(Q), alphabet(sigma), initial_state(q0), is_final(A),
      transition(delta) {}

bool DFA::match(std::string input) {
  State *current_state = initial_state;
  for (char c : input) {
    current_state = transition[{current_state, c}];
  }
  return is_final[current_state];
}