#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

#include "utils.h"

using namespace std;

class Solution {
public:
  // clean solution learn from others.
  int trap(vector<int> nums, int n) {
    int left = 0;
    int right = n - 1;
    int res = 0;
    int maxleft = 0, maxright = 0;
    while (left <= right) {
      if (nums[left] <= nums[right]) {
        if (nums[left] >= maxleft)
          maxleft = nums[left];
        else
          res += maxleft - nums[left];
        left++;
      } else {
        if (nums[right] >= maxright)
          maxright = nums[right];
        else
          res += maxright - nums[right];
        right--;
      }
    }
    return res;
  }
};

int main() { return 0; }
