#include <bits/stdc++.h>

#include "utils.h"

using namespace std;

class Solution {
 public:
  int combinationSum4(vector<int>& nums, int target) {
    vector<unsigned int> dp(target + 1, 0);
    dp[0] = 1;
    for (int i = 1; i <= target; i++) {
      unsigned int val = 0;
      for (int x : nums) {
        if (i - x >= 0)
          val += dp[i - x];
      }
      dp[i] = val;
    }
    return dp.back();
  }
};

int main(int argc, char** argv) {
  Solution sln;
  if (argc < 3) {
    printf(" Usage: %s [input array][target]\n", argv[0]);
    return 0;
  }

  vector<int> input = parseIntVector(argv[1]);

  int target = atoi(argv[2]);
  std::cout << "input is " << input << " target is " << target << std::endl;

  int result = sln.combinationSum4(input, target);
  cout << "result is " << result << endl;
  return 0;
}
