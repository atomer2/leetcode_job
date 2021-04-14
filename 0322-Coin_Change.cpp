#include <limits.h>
#include <algorithm>
#include <iostream>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>

#include "utils.h"

using namespace std;

class Solution {
 public:
  // classic DP.
  int coinChange(vector<int>& coins, int amount) {
    vector<int> dp(amount + 1);
    dp[0] = 0;
    for (int i = 1; i <= amount; i++) {
      int lst = INT_MAX;
      for (int j = 0; j < coins.size(); j++) {
        int lastIndex = i - coins[j];
        if (lastIndex >= 0 && dp[lastIndex] != -1)
          lst = min(lst, 1 + dp[lastIndex]);
      }
      dp[i] = (lst == INT_MAX) ? -1 : lst;
    }
    return dp[amount];
  }
};

int main() {
  Solution sln;
  vector<int> coins = {1,2, 5};
  cout << "min coin is :" << sln.coinChange(coins, 11);
  return 0;
}
