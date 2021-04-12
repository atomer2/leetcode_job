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
  int rob(vector<int> &nums) {
    vector<int> dp(nums.size());
    int r = INT_MIN;
    for (int i = 0; i < nums.size(); i++) {
      int tmp = nums[i];
      if (i > 1)
        tmp = nums[i] + dp[i - 2];
      if (i > 2)
        tmp = max(tmp, nums[i] + dp[i - 3]);

      dp[i] = tmp;
      r = max(dp[i], r);
    }
    return r;
  }
};

int main() { return 0; }
