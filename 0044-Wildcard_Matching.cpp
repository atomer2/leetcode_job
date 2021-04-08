#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

#include "utils.h"

using namespace std;

class Solution {
public:
  bool isMatch(string s, string p) { return isMatchDP(s, p); }

  bool isMatchRecursive(const char *s, const char *p) { return false; }

  bool isMatchDP(const string &s, const string &p) {

    vector<vector<bool>> dp(s.size() + 1, vector<bool>(p.size() + 1, false));

    int m = s.size(), n = p.size();
    dp[m][n] = true;

    for (int i = m; i >= 0; i--) {
      for (int j = n - 1; j >= 0; j--) {
        if (p[j] == '*') {
          dp[i][j] = (i < m && (dp[i + 1][j])) || dp[i][j + 1];
        } else {
          bool firstMatch = i != m && (p[j] == s[i] || p[j] == '?');
          dp[i][j] = firstMatch && dp[i + 1][j + 1];
        }
      }
    }
    return dp[0][0];
  }

  // Fastest method learn from others.
  // very clever.
  bool isMatchFast(const string &s, const string &p) {
    int m = s.size();
    int n = p.size();
    int startpos = -1;
    int last_match = -1;
    int i = 0, j = 0;
    while (i < m) {
      if (j < n && (s[i] == p[j] || p[j] == '?')) {
        i++;
        j++;
      } else if (j < n && p[j] == '*') {
        startpos = j;
        j = startpos + 1;
        last_match = i;
      } else if (startpos != -1) {
        j = startpos + 1;
        i = ++last_match;
      } else {
        return false;
      }
    }
    while (j < n && p[j] == '*')
      j++;
    return j == n;
  }
};

int main() {
  Solution sln;
  cout << "Match ? " << sln.isMatch("abced", "*a*b") << endl;
  return 0;
}
