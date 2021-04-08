#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

#include "utils.h"

using namespace std;

class Solution {
public:
  // Using KMP algorithm for pattern searching.
  // See https://www.geeksforgeeks.org/kmp-algorithm-for-pattern-searching/
  int strStr(string haystack, string needle) {
    if (needle.empty())
      return 0;
    vector<int> lps = computeLPSArray(needle);
    int m = needle.size();
    int n = haystack.size();
    int i = 0, j = 0;
    while (i < n) {
      if (haystack[i] == needle[j]) {
        i++;
        j++;
      }
      if (j == m) {
        return i - m;
      } else if (i < n && haystack[i] != needle[j]) {
        if (j != 0)
          j = lps[j - 1];
        else
          i++;
      }
    }
    return -1;
  }

  // name lps indicates longest proper prefix which is also suffix. A proper
  // prefix is prefix with whole string not allowed. For example, prefixes of
  // "ABC" are "", "A", "AB" and "ABC". Proper prefix are "", "A", "AB".
  // Suffixes of the string are "", "C", "BC" and "ABC".
  vector<int> computeLPSArray(string pat) {
    vector<int> lps(pat.size(), 0);
    if (pat.empty())
      return lps;
    lps[0] = 0;
    int len = 0;
    int i = 1;
    while (i < pat.size()) {
      if (pat[len] == pat[i]) {
        len++;
        lps[i] = len;
        i++;
      } else {
        // This is tricky. Consider the example AAACAAAA and i=7.
        if (len != 0) {
          len = lps[len - 1];
          // Also, note that we do not increment i here.
        } else {
          lps[i] = 0;
          i++;
        }
      }
    }
    return lps;
  }
};

int main() { return 0; }
