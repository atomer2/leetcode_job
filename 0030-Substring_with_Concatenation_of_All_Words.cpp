#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<int> findSubstring(string s, vector<string>& words) {
    int sl = s.size();
    int wl = words.empty() ? 0 : words[0].size();

    vector<int> result;
    unordered_map<string, int> sdict;

    for (auto w : words)
      sdict[w]++;

    for (int i = 0; i < wl; ++i) {  // (Tom): clever
      int left = i;
      int cnt = 0;
      unordered_map<string, int> cdict;
      for (int j = i; j <= sl - wl; j += wl) {
        auto subs = s.substr(j, wl);
        if (sdict.count(subs)) {
          cdict[subs]++;
          while (cdict[subs] > sdict[subs]) {
            auto pops = s.substr(left, wl);
            left += wl;
            cnt--;
            cdict[pops]--;
          }
          cnt++;
          if (cnt == words.size()) {
            result.push_back(left);
            auto pops = s.substr(left, wl);
            cdict[pops]--;
            left += wl;
            cnt--;
          }
        } else {
          left = j + wl;
          cdict.clear();
          cnt = 0;
        }
      }
    }
    return result;
  }
};

int main() {
  Solution solution;
  string s = "barfoothefoobarman";
  vector<string> words = {"foo", "bar"};
  auto result = solution.findSubstring(s, words);
  for (auto e : result) {
    cout << e << ' ';
  }
  system("pause");
  return 0;
}