#include <iostream>
#include <map>
using namespace std;

// TC O(n)
class Solution {
 public:
  int lengthOfLongestSubstring(string s) {
    map<char,int> posmap;
    int maxlen = 0;
    int pre = -1;

    for (int i = 0; i < s.size(); ++i) {
      auto itor = posmap.find(s[i]);
      int oldpos = -1;
      if (itor != posmap.end())
        oldpos = itor->second;
      posmap[s[i]] = i;
      int len = 0;
      if (pre >= oldpos) {
        len = i - pre;
      } else {
        pre = oldpos;
        len = i - pre;
      }
      if (len > maxlen)
        maxlen = len;
    }
    return maxlen;
  }
};

int main() {
  Solution solution;
  string s = "abcabcbb";
  cout << solution.lengthOfLongestSubstring(s) << endl;
  system("pause");
}