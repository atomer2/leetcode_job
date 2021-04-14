#include <algorithm>
#include <iostream>
#include <limits.h>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>

#include "utils.h"

using namespace std;

class Solution {
public:
  void gameOfLife(vector<vector<int>> &board) {
    // clever way to get neighbor.
    int nn[] = {0, 1, 0, -1, 1, 1, -1, -1, 0};
    int m = board.size();
    int n = board[0].size();
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        int lives = 0;
        for (int k = 0; k < 8; k++) {
          int r = i + nn[k], c = j + nn[k + 1];
          if (r >= 0 && r < m && c >= 0 && c < n) {
            if ((board[r][c] & 1))
              lives++;
          }
        }
        if (board[i][j] == 1) {
          if (lives == 2 || lives == 3)
            board[i][j] += 2;
        } else {
          if (lives == 3)
            board[i][j] += 2;
        }
      }
    }
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (board[i][j] == 2 || board[i][j] == 3)
          board[i][j] = 1;
        else
          board[i][j] = 0;
      }
    }
  }
};

int main() { return 0; }
