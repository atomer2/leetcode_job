#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  // DP solution.
  int numDecodings(string s) {
    // backward.
    vector<long long> table(s.size() + 1, 0);
    table.back() = 1;
    for (int i = s.size() - 1; i >= 0; i--) {
      if (s[i] != '0') {
        int res = table[i + 1];
        if (i + 2 < table.size() &&
            ((s[i] == '2' && s[i + 1] <= '6') || (s[i] == '1'))) {
          res += table[i + 2];
        }
        table[i] = res;
      }
    }
    return table[0];
  }

  // forward.
  int numDecodings2(string s) {
    vector<int> dp(s.size() + 1, 0);
    if (s.empty() || s[0] == '0')
      return 0;
    dp[0] = 1;
    dp[1] = 1;
    for (int i = 1; i < s.size(); i++) {
      int count = s[i] != '0' ? dp[i] : 0;
      if ((s[i - 1] == '2' && s[i] <= '6') || s[i - 1] == '1')
        count += dp[i - 1];
      dp[i + 1] = count;
    }
    return dp.back();
  }
};
