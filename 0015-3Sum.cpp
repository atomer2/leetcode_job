#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

#include "utils.h"

using namespace std;

class Solution {
public:
  vector<vector<int>> threeSum(vector<int> nums) {
    std::sort(nums.begin(), nums.end());
    vector<vector<int>> ret;
    int n = nums.size();
    // Don't use this, because nums.size() is unsigned!
    // for(int i = 0; i< nums.size() - 2; i++)
    for (int i = 0; i < n - 2; i++) {
      int target = -nums[i];
      int l = i + 1, r = nums.size() - 1;
      while (l < r) {
        int sum = nums[l] + nums[r];
        if (sum == target) {
          ret.push_back(vector<int>{nums[i], nums[l], nums[r]});
          l++;
          while (l < r && nums[l] == nums[l - 1])
            l++;
        } else if (sum > target) {
          r--;
        } else {
          l++;
        }
      }
      while (i < nums.size() - 2 && nums[i] == nums[i + 1])
        i++;
    }
    return ret;
  }
};

int main() { return 0; }
