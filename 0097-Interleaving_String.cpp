#include <iostream>
#include <vector>
#include <string>

// DP
using namespace std;

class Solution {
 public:
  bool isInterleave(string s1, string s2, string s3) {
    if (s1.size() + s2.size() != s3.size())
      return false;

    string& ss = s1.size() > s2.size() ? s2 : s1;
    string& bs = s1.size() > s2.size() ? s1 : s2;

    if (ss.empty())
      return bs == s3;

    vector<bool> table(ss.size() + 1, true);
    for (size_t i = 1; i < table.size(); ++i) {
      if (table[i - 1] && ss[i - 1] == s3[i - 1])
        table[i] = true;
      else
        table[i] = false;
    }
    for (size_t i = 0; i < bs.size(); ++i) {
      for (size_t j = 0; j < table.size(); ++j) {
        if (j == 0) {
          if (!table[j] || bs[i] != s3[i])
            table[j] = false;
        } else {
          if (table[j - 1] && ss[j - 1] == s3[i + j]) {
            table[j] = true;
          } else if (table[j] && bs[i] == s3[i + j]) {
            table[j] = true;
          } else {
            table[j] = false;
          }
        }
      }
    }
    return table.back();
  }
};
