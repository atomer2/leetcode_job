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
  int firstUniqChar(string s) {
    int freq[26] = {
        0,
    };
    for (int i = 0; i < s.length(); i++) {
      freq[s[i] = 'a']++;
    }

    for (int i = 0; i < s.length(); i++) {
      if (freq[s[i] - 'a'] == 1)
        return i;
    }
    return -1;
  }
};

int main() {
  return 0;
}