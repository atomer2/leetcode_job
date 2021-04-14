#include <algorithm>
#include <deque>
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
  // Very subtle.
  vector<int> maxSlidingWindow(vector<int> &nums, int k) {
    deque<int> q;
    vector<int> r;
    int n = nums.size();

    for (int i = 0; i < n; i++) {
      while (!q.empty() && nums[q.back()] < nums[i])
        q.pop_back();
      q.push_back(i);

      if (i - q.front() == k)
        q.pop_front();

      if (i + 1 >= k)
        r.push_back(nums[q.front()]);
    }

    return r;
  }
};

int main() { return 0; }
