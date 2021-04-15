#include <limits.h>
#include <algorithm>
#include <iostream>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>

#include "utils.h"

using namespace std;

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
    int r = 0;
    int last = start;
    for (int i = start; i <= end; i++) {
      if (count[s[i] - 'a'] < k) {
        if (i - last >= max(k, r + 1)) {
          int len = helpFunc(s, last, i - 1, k);
          r = max(len, r);
        }
        last = i + 1;
      } else if (i == end) {
        int len = last == start ? (end - start + 1) : helpFunc(s, last, i, k);
        r = max(len, r);
      }
    }

    return r;
  }
};

int main() {
  string input = "bbaaacbd";
  Solution sln;
  cout << "answer is " << sln.longestSubstring(input, 3) << endl;
  return 0;
}
