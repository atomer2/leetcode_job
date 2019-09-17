#include <vector>
#include <string>

using namespace std;

// backtrace
class Solution {
 public:
  vector<string> restoreIpAddresses(string s) {
    vector<string> res;
    vector<string> acc;
    if (s.size() < 4)
      return res;
    backtrace(res, acc, 0, 4, s);
    return res;
  }

  void backtrace(vector<string>& res,
                 vector<string>& acc,
                 size_t pos,
                 int field,
                 string& s) {
    if (pos == s.size() && field == 0) {
      string ss;
      for (size_t i = 0; i < acc.size() - 1; i++) {
        ss += acc[i] + '.';
      }
      ss += acc.back();
      res.push_back(ss);
      return;
    }
    if (pos == s.size() || field == 0)
      return;
    acc.push_back(s.substr(pos, 1));
    backtrace(res, acc, pos + 1, field - 1, s);
    acc.pop_back();

    if (pos + 1 < s.size() && s[pos] != '0') {
      acc.push_back(s.substr(pos, 2));
      backtrace(res, acc, pos + 2, field - 1, s);
      acc.pop_back();
    }
    if (pos + 2 < s.size() &&
        (s[pos] == '1' ||
         (s[pos] == '2' &&
          (s[pos + 1] < '5' || (s[pos + 1] == '5' && s[pos + 2] <= '5'))))) {
      acc.push_back(s.substr(pos, 3));
      backtrace(res, acc, pos + 3, field - 1, s);
      acc.pop_back();
    }
  }
};
