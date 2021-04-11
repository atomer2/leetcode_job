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
  // Very clever solution learn from others.
  int findPeakElement(vector<int> nums) {
    int low = 0;
    int high = nums.size() - 1;
    while (low < high) {
      int mid1 = (low + high) / 2;
      int mid2 = mid1 + 1;
      if (nums[mid1] < nums[mid2])
        low = mid2;
      else
        high = mid1;
    }
    return low;
  }
};

int main() { return 0; }
