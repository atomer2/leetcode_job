#include <iostream>
#include <vector>

using namespace std;

// DP solution
class Solution {
 public:
  vector<int> grayCode(int n) {
    vector<vector<int>> table;
    vector<int> init = {0};
    table.push_back(init);
    for (int i = 0; i < n; ++i) {
      vector<int> tmp;
      for (int j = 0; j < table[i].size(); ++j) {
        tmp.push_back(table[i][j]);
      }
      for (int j = table[i].size() - 1; j >= 0; --j) {
        tmp.push_back(table[i][j] | (1 << i));
      }
      table.push_back(tmp);
    }
    return table.back();
  }
};
