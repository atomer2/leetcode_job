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
  vector<int> productExceptSelf(vector<int> &nums) {
    int n = nums.size();
    vector<int> r(n);
    r[0] = 1;
    for (int i = 1; i < n; i++) {
      r[i] = r[i - 1] * nums[i - 1];
    }
    int right = 1;
    for (int i = n - 1; i >= 0; i--) {
      r[i] *= right;
      right *= nums[i];
    }
    return r;
  }
};

int main() { return 0; }
