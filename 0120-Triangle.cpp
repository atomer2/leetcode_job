class Solution {
public:
  int minimumTotal(vector<vector<int>> &triangle) {
    int row = triangle.size();
    vector<int> tmp(row + 1, 0);
    for (int i = row - 1; i >= 0; i--) {
      for (int j = 0; j <= i; j++) {
        tmp[j] = min(tmp[j] + triangle[i][j], tmp[j + 1] + triangle[i][j]);
      }
    }
    return tmp[0];
  }
};

