#include <string>
#include <vector>

using namespace std;
// backtrack
class Solution {
public:
  bool exist(vector<vector<char>> &board, string word) {

    if (board.empty())
      return false;

    int rows = board.size();
    int cols = board[0].size();

    for (int i = 0; i < rows; ++i) {
      for (int j = 0; j < cols; ++j) {
        if (backtrack(board, word, 0, i, j))
          return true;
      }
    }
    return false;
  }

  bool backtrack(vector<vector<char>> &board, string &word, int pos, int m,
                 int n) {
    if (pos == word.size())
      return true;

    if (m < 0 || m >= board.size() || n < 0 || n >= board[0].size())
      return false;

    // clever! see below.
    if (board[m][n] != word[pos])
      return false;

    // Excellent idea, use high order bit to indicate if we have already touched
    // this position. This works because we only use English letters.
    board[m][n] ^= 256;
    pos++;

    if (backtrack(board, word, pos, m - 1, n))
      return true;
    if (backtrack(board, word, pos, m, n - 1))
      return true;
    if (backtrack(board, word, pos, m + 1, n))
      return true;
    if (backtrack(board, word, pos, m, n + 1))
      return true;

    board[m][n] ^= 256;
    return false;
  }
};
