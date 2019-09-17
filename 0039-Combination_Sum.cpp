#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

using namespace std;

// using backtracing algorithm

class Solution {
 public:
  vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<int> acc;
    vector<vector<int>> res;
    backTracing(candidates, 0, acc, res, target);
    return res;
  }

 private:
  void backTracing(vector<int>& candidates,
                   int i,
                   vector<int>& acc,
                   vector<vector<int>>& res,
                   int target) {
    for (int j = i; j < candidates.size(); ++j) {
      if (candidates[j] == target) {
        acc.push_back(candidates[j]);
        res.push_back(acc);
        acc.pop_back();
      } else if (candidates[j] < target) {
        acc.push_back(candidates[j]);
        backTracing(candidates, j, acc, res, target - candidates[j]);
        acc.pop_back();
      }
    }
  }
};

int main() {
  vector<int> arr = {2, 3, 6, 7};
  Solution s;
  auto res = s.combinationSum(arr, 7);
  system("pause");
}
