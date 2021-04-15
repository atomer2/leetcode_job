#include <limits.h>
#include <algorithm>
#include <iostream>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>

#include "utils.h"

using namespace std;

class Solution {
 public:
  int longestSubstring(string s, int k) {
    return helpFunc(s, 0, s.size() - 1, k);
  }

  int helpFunc(const string& s, int start, int end, int k) {
    int count[26] = {
        0,
    };
    for (int i = start; i <= end; i++) {
      count[s[i] - 'a']++;
    }
    int r = -1;
    int cut = 0;
    int last = start;
    for (int i = start; i <= end; i++) {
      if (count[s[i] - 'a'] < k) {
        cut = 1;
        if (i - last >= max(k, r + 1)) {
          int len = helpFunc(s, last, i - 1, k);
          r = max(len, r);
        }
        last = i + 1;
      }
    }

    return cut ? r : end - start + 1;
  }
};

int main() {
  return 0;
}