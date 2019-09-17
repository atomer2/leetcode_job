// hard problem
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <climits>

using namespace std;

class Solution {
 public:
  string minWindow(string s, string t) {
    unordered_map<char, int> h;
    int minLen = INT_MAX;
    int minLeft = 0;

    if (t.size() > s.size())
      return string();

    int left = 0;
    int right = 0;
    for (auto& e : t)
      h[e]++;

    int match = h.size();

    for (size_t i = 0; i < s.size(); ++i) {
      if (--h[s[i]] == 0) {
        if (--match == 0) {
          right = i;
          while (++h[s[left++]] <= 0)
            ;
          if (minLen > right - left + 2) {
            minLen = right - left + 2;
            minLeft = left - 1;
          }
          match++;
        }
      }
    }
    return minLen == INT_MAX ? string() : s.substr(minLeft, minLen);
  }
};

int main() {
  Solution solution;
  string str1 = "aa";
  string str2 = "aa";
  cout << solution.minWindow(str1, str2) << endl;
  return 0;
}
