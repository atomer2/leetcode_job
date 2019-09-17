#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<int> spiralOrder(vector<vector<int>>& matrix) {
    vector<int> result;
    int h = matrix.size();
    int w = matrix.empty() ? 0 : matrix[0].size();
    for (int i = 0; i < matrix.size(); ++i) {
      getLayer(matrix, result, i, w, h);
    }
    return result;
  }

  void getLayer(vector<vector<int>>& matrix,
                vector<int>& res,
                int n,
                int w,
                int h) {
    int endx = w - n;
    int endy = h - n;
    if (n >= endx || n >= endy)
      return;
    if (endy - n == 1) {
      for (int i = n; i < endx; ++i)
        res.push_back(matrix[n][i]);
      return;
    }
    if (endx - n == 1) {
      for (int i = n; i < endy; ++i)
        res.push_back(matrix[i][n]);
      return;
    }
    for (int i = n; i < endx; ++i) {
      res.push_back(matrix[n][i]);
    }
    for (int i = n + 1; i < endy; ++i) {
      res.push_back(matrix[i][endx - 1]);
    }
    for (int i = endx - 2; i >= n; --i) {
      res.push_back(matrix[endy - 1][i]);
    }
    for (int i = endy - 2; i > n; --i) {
      res.push_back(matrix[i][n]);
    }
  };
};

int main() {
  Solution solution;
  vector<vector<int>> input{{7}, {8}, {9}};
  auto result = solution.spiralOrder(input);
  for (auto& e : result)
    cout << e << ' ';
  cout << endl;
  return 0;
}
