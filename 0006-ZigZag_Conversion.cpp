#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
class Solution {
 public:
  string convert(string s, int numRows) {
    if (numRows == 1)
      return s;
    int rows = min(int(s.size()), numRows);
    vector<string> s_arr(rows);
    bool bGoingDown = false;
    int currRow = 0;
    for (char c : s) {
      if (currRow == 0 || currRow == rows - 1)
        bGoingDown = !bGoingDown;
      s_arr[currRow] += c;
      currRow += bGoingDown ? 1 : -1;
    }
    string resString;
    for (auto& subs : s_arr) {
      resString += subs;
    }
    return resString;
  }
};
int main() {
  string s = "PAYPALISHIRING";
  Solution solution;
  cout << solution.convert(s, 4) << endl;
  system("pause");
}