#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
 public:
  vector<vector<int>> insert(vector<vector<int>>& intervals,
                             vector<int>& newInterval) {
    vector<vector<int>> res;
    auto i0 = intervals.begin();
    auto i1 = intervals.rbegin();
    for (; i0 != intervals.end(); i0++) {
      if ((*i0)[1] >= newInterval[0])
        break;
    }
    if (i0 == intervals.end()) {
      res = intervals;
      res.push_back(newInterval);
      return res;
    }
    for (; i1 != intervals.rend(); i1++) {
      if ((*i1)[0] <= newInterval[1])
        break;
    }
    if (i1 == intervals.rend()) {
      res.push_back(newInterval);
      for (auto& e : intervals)
        res.push_back(e);
      return res;
    }
    for (auto it = intervals.begin(); it != i0; it++) {
      res.push_back(*it);
    }
    vector<int> merge = newInterval;
    merge[0] = min((*i0)[0], merge[0]);
    merge[1] = max((*i1)[1], merge[1]);
    res.push_back(merge);
    if (i1 != intervals.rbegin()) {
      auto i = i1;
      do {
        i = prev(i);
        res.push_back(*i);
      } while (i != intervals.rbegin());
    }
    return res;
  }
};

int main() {
  vector<vector<int>> intervals{{1, 2}, {3, 5}, {6, 7}, {8, 10}, {12, 16}};
  vector<int> newInterval{4, 8};
  Solution solution;
  solution.insert(intervals, newInterval);
  auto It = upper_bound(intervals.begin(), intervals.end(), newInterval);
  for (auto& e : *It)
    cout << e << ' ';
  cout << endl;
}
