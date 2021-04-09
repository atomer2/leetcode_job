#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

#include "utils.h"

using namespace std;

class Solution {
public:
  bool canJump(vector<int> &nums) {
    int rightMost = 0;
    for (int i = 0; i < nums.size() - 1; i++) {
      if (i == rightMost && nums[i] == 0)
        return false;
      rightMost = max(rightMost, nums[i] + i);
    }
    return true;
  }
};

int main() { return 0; }
