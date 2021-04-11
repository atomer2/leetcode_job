#include <algorithm>
#include <iostream>
#include <limits.h>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>

#include "utils.h"

using namespace std;

class MinStack {
public:
  MinStack() {}

  void push(int val) {
    stk1.push_back(val);
    if (stk2.empty() || stk2.back() > val)
      stk2.push_back(val);
    else
      stk2.push_back(stk2.back());
  }

  void pop() {
    stk1.pop_back();
    stk2.pop_back();
  }

  int top() { return stk1.back(); }

  int getMin() { return stk2.back(); }

  vector<int> stk1;
  vector<int> stk2;
};

int main() { return 0; }
