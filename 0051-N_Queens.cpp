#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
 public:
  vector<vector<string>> solveNQueens(int n) {
    vector<vector<string>> res;
    vector<string> tres;
    solveNQueensRecursive(tres, res, n, n, 0, 0, 0);
    return res;
  }

  void solveNQueensRecursive(vector<string>& tres,
                             vector<vector<string>>& res,
                             int n,
                             int line,
                             int rmark,
                             int lmark,
                             int mark) {
    if (line == 0) {
      res.push_back(tres);
      return;
    }
    string s(n, '.');
    int cmark = rmark | lmark | mark;
    for (int i = 0; i < n; ++i) {
      if (!(cmark & (1 << i))) {
        int nmark = 1 << i;
        s[i] = 'Q';
        tres.push_back(s);
        solveNQueensRecursive(tres, res, n, line - 1, (rmark | nmark) >> 1,
                              (lmark | nmark) << 1, (mark | nmark));
        tres.pop_back();
        s[i] = '.';
      }
    }
  }
};

int main() {
  Solution solution;
  auto result = solution.solveNQueens(8);
  cout << '[' << endl;
  for (auto& e : result) {
    cout << '[' << endl;
    for (auto& s : e) {
      cout << s << endl;
    }
    cout << ']' << endl;
  }
  cout << ']' << endl;
  return 0;
}
