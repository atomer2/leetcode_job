#include <algorithm>
#include <iostream>
#include <limits.h>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>

#include "utils.h"

using namespace std;

// clever solution learn from others.
class Solution {
public:
  int maxProduct(vector<int> &nums) {
    if (nums.empty())
      return 0;

    int r = nums[0];
    for (int i = 1, imax = r, imin = r; i < nums.size(); i++) {
      if (nums[i] < 0)
        swap(imax, imin);

      imax = max(nums[i], imax * nums[i]);
      imin = min(nums[i], imin * nums[i]);

      r = max(r, imax);
    }
    return r;
  }
};

int main() { return 0; }
