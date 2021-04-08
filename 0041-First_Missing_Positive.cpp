#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

#include "utils.h"

using namespace std;

class Solution {
public:
  int firstMissingPositive(vector<int> &nums) {
    int n = nums.size();
    for (int i = 0; i < n; i++) {
      while (nums[i] != i + 1 &&
             // underflow!
             // nums[i] - 1 >= 0 &&
             // nums[i] - 1 < n &&
             nums[i] >= 1 && 
             nums[i] < n + 1 && 
             nums[i] != nums[nums[i] - 1]) {
        swap(nums[i], nums[nums[i] - 1]);
      }
    }
    for (int i = 0; i < nums.size(); i++) {
      if (nums[i] != i + 1)
        return i + 1;
    }
    return nums.size() + 1;
  }
};

int main() { return 0; }
