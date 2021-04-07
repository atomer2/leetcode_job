#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

#include "utils.h"

using namespace std;

class Solution {
public:
  vector<string> letterCombinations(string digits) {
    vector<string> vs;
    unordered_map<char, string> sMap = {
        {'2', "abc"}, {'3', "def"},  {'4', "ghi"}, {'5', "jkl"},
        {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}};
    if (digits.empty())
      return vs;
    int n = digits.size();
    vector<string> strs(n);
    vector<int> counter(n, 0);
    for (int i = 0; i < n; i++) {
      strs[i] = sMap[digits[i]];
    }
    while (true) {
      int carry = 0;
      string str;
      for (int i = 0; i < n; i++) {
        counter[i] += carry;
        if (counter[i] >= strs[i].size()) {
          if(i == n-1)
            return vs;
          // wrap
          counter[i] = 0;
          carry = 1;
        } else {
          carry = 0;
        }
        str.push_back(strs[i][counter[i]]);
        if (i == 0)
          counter[i]++;
        if (i == n - 1)
          vs.push_back(str);
      }
    }
    return vs;
  }
};

int main() { return 0; }
