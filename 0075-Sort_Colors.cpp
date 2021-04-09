#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

#include "utils.h"

using namespace std;

class Solution {
public:
  // one pass
  /*
   * The meaning of left, i, and right：
   *
   * 000000111111XXXXXX222222
   *       ^     ^    ^
   *      left   i  right
   **/
  void sortColors(vector<int> &nums) {
    size_t cnt = nums.size();
    int i = 0;
    int left = 0;
    int right = cnt - 1;
    while (i <= right) {
      if (nums[i] == 2) {
        swap(nums[i], nums[right]);
        right--;
      } else if (nums[i] == 0) {
        swap(nums[i], nums[left]);
        left++;
        i++;
      } else {
        i++;
      }
    }
  }
};

int main() { return 0; }
