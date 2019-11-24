#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<vector<string>> findLadders(string beginWord,
                                     string endWord,
                                     vector<string>& wordList) {
    unordered_set<string> wordSet(wordList.begin(), wordList.end());
    unordered_set<string> visitedSet;
    // For path building, avoid cycle reference
    unordered_set<string> lastVisitedSet;
    unordered_set<string> beginSet;
    unordered_set<string> endSet;
    bool minLengthSet = false;
    vector<vector<string>> res;
    int wl = beginWord.size();
    if (wordSet.find(endWord) == wordSet.end())
      return res;

    unordered_map<string, unordered_set<string>> predecessor[2];
    int phase = 0;
    beginSet.insert(beginWord);
    endSet.insert(endWord);
    while (!beginSet.empty() && !endSet.empty() && !minLengthSet) {
      if (beginSet.size() > endSet.size()) {
        swap(beginSet, endSet);
        phase ^= 1;
      }
      lastVisitedSet = visitedSet;

      unordered_set<string> tempSet;
      for (auto& ce : beginSet) {
        string e = ce;
        for (int i = 0; i < wl; i++) {
          char oldChar = e[i];
          for (char c = 'a'; c <= 'z'; c++) {
            e[i] = c;
            if (wordSet.find(e) != wordSet.end()) {
              if (endSet.find(e) != endSet.end()) {
                minLengthSet = true;
                buildPath(predecessor[0], predecessor[1], phase ? e : ce,
                          phase ? ce : e, beginWord, endWord, res);
              } else if (visitedSet.find(e) == visitedSet.end()) {
                visitedSet.insert(e);
                tempSet.insert(e);
              }
              if (lastVisitedSet.find(e) == lastVisitedSet.end()) {
                auto& predecessorRef = predecessor[phase];
                predecessorRef[e].insert(ce);
              }
            }
          }
          e[i] = oldChar;
        }
      }
      swap(beginSet, tempSet);
    }
    return res;
  }

  void buildPath(unordered_map<string, unordered_set<string>>& forward,
                 unordered_map<string, unordered_set<string>>& backward,
                 const string& fmid,
                 const string& bmid,
                 const string& beginWord,
                 const string& endWord,
                 vector<vector<string>>& res) {
    vector<vector<string>> facc;
    vector<vector<string>> bacc;
    vector<string> ftmp;
    vector<string> btmp;
    buildPathBackTrace(forward, fmid, beginWord, ftmp, facc);
    buildPathBackTrace(backward, bmid, endWord, btmp, bacc);
    for (auto vs : facc) {
      reverse(vs.begin(), vs.end());
      for (const auto& bs : bacc) {
        auto vsn = vs;
        vsn.insert(std::end(vsn), std::begin(bs), std::end(bs));
        res.push_back(vsn);
      }
    }
  }

  void buildPathBackTrace(unordered_map<string, unordered_set<string>>& pre,
                          const string& start,
                          const string& end,
                          vector<string>& tmpStr,
                          vector<vector<string>>& res) {
    tmpStr.push_back(start);
    if (start == end) {
      res.push_back(tmpStr);
    } else {
      auto& preSet = pre[start];
      for (auto& e : preSet) {
        buildPathBackTrace(pre, e, end, tmpStr, res);
      }
    }
    tmpStr.pop_back();
  }
};

int main() {
  string beginWord("hit");
  string endWord("cog");
  vector<string> wordList{"hot", "dot", "dog", "lot", "log", "cog"};
  Solution s;
  auto res = s.findLadders(beginWord, endWord, wordList);
  cout << "[" << endl;
  for (auto v : res) {
    cout << "[ ";
    for (auto e : v)
      cout << e << ", ";
    cout << "]" << endl;
  }
  cout << "]" << endl;
  return 0;
}
