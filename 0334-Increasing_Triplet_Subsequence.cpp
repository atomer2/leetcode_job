#include <limits.h>
#include <algorithm>
#include <iostream>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>

#include "utils.h"

using namespace std;

class Solution {
 public:
  // This question is very similar to "The Longest Increasing Subsequence"
  // problem, because we know that we just need triplet, so we can use just two
  // variable instead of a vector.

  // genius.
  bool increasingTriplet(vector<int>& nums) {
    int small = INT_MAX, big = INT_MAX;
    for (int i : nums) {
      if (i <= small)
        small = i;
      else if (i <= big)
        big = i;
      else
        return true;
    }
    return false;
  }
};

int main() {
  return 0;
}
