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
  // Extremely smart!
  int findDuplicate(vector<int> &nums) {
    int hare = 0, tortoise = 0;
    while (1) {
      hare = nums[hare];
      hare = nums[hare];
      tortoise = nums[tortoise];
      if (hare == tortoise)
        break;
    }
    hare = 0;
    while (hare != tortoise) {
      hare = nums[hare];
      tortoise = nums[tortoise];
    }
    return hare;
  }
};

int main() { return 0; }
