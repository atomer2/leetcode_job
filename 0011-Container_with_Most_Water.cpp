#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

#include "utils.h"

using namespace std;

class Solution {
public:
  int maxArea(vector<int> &height) {
    int ret = 0;
    int l = 0, r = height.size() - 1;
    int last;
    while (l < r) {
      last = min(height[l], height[r]);
      int m = last * (r - l);
      ret = max(ret, m);
      while (l < r && height[l] <= last)
        l++;
      while (l < r && height[r] <= last)
        r--;
    }
    return ret;
  }
};

int main() {
  vector<int> input = {1, 8, 6, 2, 5, 4, 8, 3, 7};
  Solution sln;
  int ret = sln.maxArea(input);
  cout << "max area is: " << ret << endl;
  return 0;
}
