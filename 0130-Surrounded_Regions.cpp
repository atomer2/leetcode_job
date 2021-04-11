#include <vector>

using namespace std;
// clever solution learn from others
class Solution {
public:
  void solve(vector<vector<char>> &board) {
    size_t h = board.size();
    if (h == 0)
      return;
    size_t w = board[0].size();
    if (w == 0)
      return;
    for (int i = 0; i < w; i++) {
      check(board, h, w, 0, i);
      if (h > 1)
        check(board, h, w, h - 1, i);
    }
    for (int i = 0; i < h; i++) {
      check(board, h, w, i, 0);
      if (w > 1)
        check(board, h, w, i, w - 1);
    }
    for (int i = 0; i < h; i++) {
      for (int j = 0; j < w; j++) {
        if (board[i][j] == '1')
          board[i][j] = 'O';
        else if (board[i][j] == 'O')
          board[i][j] = 'X';
      }
    }
  }

private:
  void check(vector<vector<char>> &board, int h, int w, int r, int c) {
    if (board[r][c] == 'O') {
      board[r][c] = '1';
      if (r > 1)
        check(board, h, w, r - 1, c);
      if (c > 1)
        check(board, h, w, r, c - 1);
      if (r < h - 1)
        check(board, h, w, r + 1, c);
      if (c < w - 1)
        check(board, h, w, r, c + 1);
    }
  }
};
