#include <climits>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int largestRectangleArea(vector<int> &heights) {
    int maxArea = 0;
    // idx of the first bar the left that is lower than current.
    vector<int> lastLeftLess(heights.size(), -1);
    // idx of the first bar the right that  is lower than current.
    vector<int> lastRightLess(heights.size(), heights.size());
    for (int i = 1; i < heights.size(); ++i) {
      int p = i - 1;
      while (p != -1 && heights[p] >= heights[i])
        p = lastLeftLess[p];
      lastLeftLess[i] = p;
    }
    for (int i = heights.size() - 2; i >= 0; --i) {
      int p = i + 1;
      while (p != heights.size() && heights[p] >= heights[i])
        p = lastRightLess[p];
      lastRightLess[i] = p;
    }
    for (int i = 0; i < heights.size(); ++i) {
      int t = heights[i] * (lastRightLess[i] - lastLeftLess[i] - 1);
      if (t > maxArea)
        maxArea = t;
    }
    return maxArea;
  }
};
