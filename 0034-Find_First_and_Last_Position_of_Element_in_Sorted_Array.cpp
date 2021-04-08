#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

#include "utils.h"

using namespace std;

class Solution {
public:
  vector<int> searchRange(vector<int> &nums, int target) {
    vector<int> range = {-1, -1};
    if (nums.empty())
      return range;
    // Find left.
    int l = 0, r = nums.size() - 1;
    while (l <= r) {
      int mid = l + ((r - l) >> 1);
      if (nums[mid] == target) {
        range[0] = mid;
        r = mid - 1;
      } else if (nums[mid] > target) {
        r = mid - 1;
      } else {
        l = mid + 1;
      }
    }
    if(range[0] == -1)
      return range;
    // Find right.
    l = 0;
    r = nums.size() - 1;
    while (l <= r) {
      int mid = l + ((r - l) >> 1);
      if (nums[mid] == target) {
        range[1] = mid;
        l = mid + 1;
      } else if (nums[mid] > target) {
        r = mid - 1;
      } else {
        l = mid + 1;
      }
    }

    return range;
  }
};

int main() { return 0; }
