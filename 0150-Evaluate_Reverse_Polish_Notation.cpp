#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

class Solution {
 public:
  int evalRPN(vector<string>& tokens) {
    stack<int> numStack;
    for (auto& e : tokens) {
      if (!isOP(e)) {
        numStack.push(stoi(e));
      } else {
        int oprand1 = numStack.top();
        numStack.pop();
        int oprand0 = numStack.top();
        numStack.pop();
        int res;
        if (e == "+") {
          res = oprand0 + oprand1;
        } else if (e == "-") {
          res = oprand0 - oprand1;
        } else if (e == "*") {
          res = oprand0 * oprand1;
        } else if (e == "/") {
          res = oprand0 / oprand1;
        }
        numStack.push(res);
      }
    }
    return numStack.top();
  }

  bool isOP(string s) { return s == "+" || s == "-" || s == "*" || s == "/"; }
};
