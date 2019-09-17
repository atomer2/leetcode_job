#include <vector>

using namespace std;

class Solution {
 public:
  int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    int m = obstacleGrid[0].size();
    int n = obstacleGrid.size();
    vector<long long> table(m, 0);
    int k = 0;
    while (k < m && obstacleGrid[0][k] == 0) {
      table[k] = 1;
      k++;
    }
    for (int i = 1; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        if (obstacleGrid[i][j] == 1)
          table[j] = 0;
        else {
          if (j != 0)
            table[j] = table[j] + table[j - 1];
        }
      }
    }
    return table.back();
  }
};
