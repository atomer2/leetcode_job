// Solution learn from others
// Bidirectional Breadth First Search
class Solution {
public:
  int ladderLength(string beginWord, string endWord, vector<string> &wordList) {
    unordered_set<string> wordSet(wordList.begin(), wordList.end());
    unordered_set<string> visitedSet;
    unordered_set<string> beginSet, endSet;
    int wl = beginWord.size();
    int res = 1;
    if (wordSet.find(endWord) == wordSet.end())
      return 0;

    beginSet.insert(beginWord);
    endSet.insert(endWord);

    while (!beginSet.empty() && !endSet.empty()) {
      if (beginSet.size() > endSet.size())
        swap(beginSet, endSet);

      unordered_set<string> tmpSet;
      for (auto &e : beginSet) {
        string ne = e;
        for (int i = 0; i < wl; i++) {
          char oldChar = ne[i];
          for (char c = 'a'; c <= 'z'; c++) {
            ne[i] = c;
            if (wordSet.find(ne) != wordSet.end()) {
              if (endSet.find(ne) != endSet.end()) {
                return res + 1;
              } else if (visitedSet.find(ne) == visitedSet.end()) {
                visitedSet.insert(ne);
                tmpSet.insert(ne);
              }
            }
          }
          ne[i] = oldChar;
        }
      }
      res++;
      swap(beginSet, tmpSet);
    }
    return 0;
  }
};
