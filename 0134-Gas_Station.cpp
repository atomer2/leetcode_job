#include <algorithm>
#include <iostream>
#include <limits.h>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>

#include "utils.h"

using namespace std;

class Solution {
public:
  // learn from others.
  // - If car starts at A and can not reach B. Any station between A and B
  // cannot reach B.(B is the first station that A cannot reach.)
  // - If the total number of gas is bigger than the total number of cost.
  // There must be a solution.
  int canCompleteCircuit(vector<int> gas, vector<int> cost) {
    int start = 0, total = 0, tank = 0;
    // if car fails at 'start', record the next station.
    for (int i = 0; i < gas.size(); i++) {
      if ((tank = tank + gas[i] - cost[i]) < 0) {
        start = i + 1;
        total += tank;
        tank = 0;
      }
    }
    return (total + tank < 0) ? -1 : start;
  }
};

int main() { return 0; }
