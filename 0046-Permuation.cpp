#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<vector<int>> permute(vector<int>& nums) {
    vector<int> init_vec(nums);
    vector<vector<int>> res;
    res.push_back(init_vec);
    int size = nums.size();
    int swapTimes = size;
    while (--size > 0) {
      swapTimes *= size;
    }
 
    int index = 0;
    while (--swapTimes) {
      int idx = index % (nums.size() - 1);
      swap(nums[idx], nums[idx + 1]);
      res.push_back(nums);
      index++;
    }
    return res;
  }
};

int main() {
  vector<int> input{1, 2, 3, 4};
  Solution solution;
  auto res = solution.permute(input);
  for (auto vec : res) {
    for (auto e : vec) {
      cout << e << ' ';
    }
    cout << endl;
  }
  system("pause");
}
