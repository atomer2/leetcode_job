#include <algorithm>
#include <iostream>
#include <limits.h>
#include <stack>
#include <stdio.h>
#include <string>
#include <unordered_map>
#include <vector>

#include "utils.h"

using namespace std;

class Solution {
public:
  // quick select.
  int findKthLargest(vector<int> &nums, int k) {
    int l = 0, r = nums.size() - 1;
    while (1) {
      int left = l;
      int right = r;
      swap(nums[k - 1], nums[left]);
      l++;
      while (l <= r) {
        // if we have input nums = [99,99], k=1, this will cause dead loop.
        // if(nums[l] >= nums[left])
        if (nums[l] > nums[left])
          l++;
        else
          swap(nums[l], nums[r--]);
      }
      // very important.
      swap(nums[left], nums[l - 1]);
      if (l == k) {
        return nums[l - 1];
      } else if (l < k) {
        r = right;
      } else {
        r = l - 1;
        l = left;
      }
    }
    return -1;
  }
};

int main() {
  vector<int> input = {3, 2, 1, 5, 6, 4};
  Solution sln;
  int k = 2;

  printf("%d th large element is %d\n", 2, sln.findKthLargest(input, 2));
  return 0;
}
