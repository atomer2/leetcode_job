#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

#include "utils.h"

using namespace std;

class Solution {
public:
  int search(vector<int> &nums, int target) {
    int l = 0, r = nums.size();
    r--;
    while (l <= r) {
      int mid = l + ((r - l) >> 1);
      if (nums[mid] == target)
        return mid;
      // Find the `good half` you can be totally sure.
      if (nums[r] > nums[mid]) {
        if (target > nums[mid] && target <= nums[r])
          l = mid + 1;
        else
          r = mid - 1;
      } else {
        if (target < nums[mid] && target >= nums[l])
          r = mid - 1;
        else
          l = mid + 1;
      }
    }
    return -1;
  }
};

int main() { return 0; }
