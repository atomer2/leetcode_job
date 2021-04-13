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
  enum Sign {
    plus,
    minus,
    multiply,
    divide,
  };

  bool isDigit(char c) { return c >= '0' && c <= '9'; }

  // clean code learn from newcoder.com
  int calculate(string s) {
    Sign lastSign = plus;
    vector<int> stk;
    int r = 0;
    int num = 0;
    for (int i = 0; i < s.size(); i++) {
      if (isDigit(s[i])) {
        // num = num * 10 + s[i] - '0' //overflow
        num = num * 10 + (s[i] - '0');
      }
      if ((!isDigit(s[i]) && s[i] != ' ') || i == s.size() - 1) {
        if (lastSign == plus)
          stk.push_back(num);
        else if (lastSign == minus)
          stk.push_back(-num);
        else if (lastSign == multiply)
          stk.back() = stk.back() * num;
        else
          stk.back() = stk.back() / num;
        if (s[i] == '+')
          lastSign = plus;
        else if (s[i] == '-')
          lastSign = minus;
        else if (s[i] == '*')
          lastSign = multiply;
        else if (s[i] == '/')
          lastSign = divide;
        num = 0;
      }
    }
    for (auto e : stk) {
      r += e;
    }
    return r;
  }
};

int main() {
  string input = "3+2*2";
  Solution sln;
  cout << "this result of " << input << "is " << sln.calculate(input) << endl;
  return 0;
}
