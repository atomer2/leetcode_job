#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
 public:
  vector<vector<int>> merge(vector<vector<int>>& intervals) {
    vector<vector<int>> res;
    sort(intervals.begin(), intervals.end());
    for (auto v : intervals) {
      if (res.empty()) {
        res.push_back(v);
      } else {
        auto i = res.back();
        if (i[1] >= v[0])
          i[1] = max(i[1], v[1]);
        else
          res.push_back(v);
      }
    }
    return res;
  }
};

int main() {
  Solution solution;
  vector<vector<int>> input{{1, 2, 3}, {2, 3, 4}, {5, 6}, {4, 1}};
  auto res = solution.merge(input);
  for (auto v : res) {
    for (auto e : v) {
      cout << e << ' ';
    }
    cout << endl;
  }
}
