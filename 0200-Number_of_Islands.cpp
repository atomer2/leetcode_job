#include <algorithm>
#include <iostream>
#include <limits.h>
#include <queue>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>

#include "utils.h"

using namespace std;

class Solution {
public:
  // BFS method learn from others.
  int numIslands(vector<vector<char>> grid) {
    int m = grid.size(), n = m ? grid[0].size() : 0, islands = 0,
        offsets[] = {0, 1, 0, -1, 0};
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (grid[i][j] == '1') {
          islands++;
          queue<pair<int, int>> todo;
          todo.push({i, j});
          while (!todo.empty()) {
            auto p = todo.front();
            todo.pop();
            for (int k = 0; k < 4; k++) {
              int r = p.first + offsets[k], c = p.second + offsets[k + 1];
              if (r >= 0 && r < m && c >= 0 && c < n && grid[r][c] == '1') {
                grid[r][c] = '0';
                todo.push({r, c});
              }
            }
          }
        }
      }
    }
    return islands;
  }
};

int main() { return 0; }
