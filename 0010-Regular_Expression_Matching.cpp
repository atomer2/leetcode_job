#include <string>
#include <vector>
using namespace std;

class Solution {
public:
  bool isMatch(string s, string p) {
    return isMatchRecursive(s.c_str(), p.c_str());
  }

  // Recursive method.
  bool isMatchRecursive(const char *s, const char *p) {
    if (*p == 0) {
      return *s == 0;
    }
    // s == "", p == "c*c*" won't pass if we use the statement below.
    // if(*s == 0) return p[0] && p[1] == '*' && p[2] == 0;
    if (p[0] == '.' && p[1] == '*')
      return isMatchRecursive(s, p + 2) ||
             (*s != 0 && isMatchRecursive(s + 1, p));
    else if (p[1] == '*')
      return isMatchRecursive(s, p + 2) ||
             (*s != 0 && s[0] == p[0] && isMatchRecursive(s + 1, p));
    else if (p[0] == '.' || p[0] == s[0])
      return *s != 0 && isMatchRecursive(s + 1, p + 1);
    else
      return false;
  }

  // Dynamic programming method.
  // Bottom up.
  bool isMatchDP(const string &s, const string &p) {
    vector<vector<bool>> dp(s.size() + 1, vector<bool>(p.size() + 1, false));
    dp[s.size()][p.size()] = true;
    // Be careful, the border condition of i and j are different.
    for (int i = s.size(); i >= 0; i--) {
      for (int j = p.size() - 1; j >= 0; j--) {
        bool firstMatch = (i != s.size() && (s[i] == p[j] || p[j] == '.'));
        if (j + 1 < p.size() && p[j + 1] == '*') {
          dp[i][j] = dp[i][j + 2] || (firstMatch && dp[i + 1][j]);
        } else {
          dp[i][j] = firstMatch && dp[i + 1][j + 1];
        }
      }
    }
    return dp[0][0];
  }
};
