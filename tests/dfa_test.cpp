#include "DFA/DFA.h"
#include <iostream>
#include <map>
#include <string>
#include <utility>
#include <vector>

int main(int argc, char const *argv[]) {
  if (argc != 2)
  {
    printf("1 argument required\n");
    return 0;
  }
  std::vector<State *> Q;
  for (int i = 0; i < 4; ++i) {
    State *q = new State();
    Q.push_back(q);
  }
  std::vector<char> sigma = {'0', '1'};

  State *q0 = Q[0];

  std::map<State *, bool> A;
  A[q0] = true;

  std::map<std::pair<State *, char>, State *> delta;
  delta[{Q[0], '0'}] = Q[1];
  delta[{Q[0], '1'}] = Q[3];
  delta[{Q[1], '0'}] = Q[0];
  delta[{Q[1], '1'}] = Q[2];
  delta[{Q[2], '0'}] = Q[3];
  delta[{Q[2], '1'}] = Q[1];
  delta[{Q[3], '0'}] = Q[2];
  delta[{Q[3], '1'}] = Q[0];

  DFA *myDFA = new DFA(Q, sigma, q0, A, delta);

  std::cout << myDFA->match(std::string(argv[1])) << std::endl;
  return 0;
}