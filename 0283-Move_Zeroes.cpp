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
  // clever solution learn from others.
  void moveZeroes(vector<int> &nums) {
    if (nums.empty())
      return;
    int insertPos = 0;
    for (auto i : nums)
      if (i != 0)
        nums[insertPos++] = i;

    while (insertPos < nums.size())
      nums[insertPos++] = 0;
  }
};

int main() { return 0; }
