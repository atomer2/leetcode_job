#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
 public:
  int minDistance(string word1, string word2) {
    const auto& ss = word1.size() > word2.size() ? word2 : word1;
    const auto& ls = word1.size() > word2.size() ? word1 : word2;
    vector<int> table(ss.size() + 1, 0);
    for (size_t i = 0; i < table.size(); ++i)
      table[i] = i;
    for (size_t i = 0; i < ls.size(); ++i) {
      int pre = table[0];
      for (size_t j = 1; j < table.size(); ++j) {
        int len1 = table[j] + 1;
        int len2 = ss[j - 1] == ls[i] ? pre : pre + 1;
        int len3 = table[j - 1] + 1;
        pre = table[j];
        table[j] = min(min(len1, len2), len3);
      }
      table[0] = i + 1;
    }
    return table.back();
  }
};
