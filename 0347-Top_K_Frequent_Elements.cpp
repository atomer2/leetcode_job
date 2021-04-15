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
  vector<int> topKFrequent(vector<int>& nums, int k) {
    vector<int> res;
    unordered_map<int, int> umap;
    for (auto i : nums) {
      umap[i]++;
    }

    // Bucket sort?
    vector<vector<int>> bucket(nums.size() + 1);
    for (auto&& e : umap) {
      bucket[e.second].push_back(e.first);
    }
    for (int i = bucket.size() - 1, j = k; i >= 0 && j > 0; i--) {
      auto& vi = bucket[i];
      while (!vi.empty() && j >= 0) {
        res.push_back(vi.back());
        vi.pop_back();
        j--;
      }
    }
    return res;
  }
};

int main() {
  return 0;
}
