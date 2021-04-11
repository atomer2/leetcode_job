#include <algorithm>
#include <iostream>
#include <limits.h>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#include "utils.h"

using namespace std;

class Solution {
public:
  bool wordBreak(string s, vector<string> &wordDict) {
    vector<bool> dp(s.size() + 1, false);
    dp[0] = true;
    unordered_set<string> set;
    for (auto &&w : wordDict) {
      set.insert(w);
    }
    for (int i = 0; i < s.length(); i++) {
      for (int j = i; j >= 0; j--) {
        if (set.count(s.substr(j, i - j + 1))) {
          if (dp[j]) {
            dp[i + 1] = true;
            break;
          }
        }
      }
    }
    return dp.back();
  }
};

int main() { return 0; }
