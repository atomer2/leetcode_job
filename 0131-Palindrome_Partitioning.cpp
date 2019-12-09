//  backtrace solution
class Solution {
public:
  vector<vector<string>> partition(string s) {
    vector<vector<string>> result;
    if (s.empty())
      return result;
    vector<string> tmpVec;
    partitionBackTrace(s, result, tmpVec, 0, s.size());
    return result;
  }

  void partitionBackTrace(const string &s, vector<vector<string>> &result,
                          vector<string> &tmpVec, int startPos, int endPos) {
    for (int i = startPos; i < endPos; i++) {
      if (isPalindrome(s, startPos, i)) {
        if (i == endPos - 1) {
          tmpVec.push_back(s.substr(startPos, i - startPos + 1));
          result.push_back(tmpVec);
          tmpVec.pop_back();

        } else {
          tmpVec.push_back(s.substr(startPos, i - startPos + 1));
          partitionBackTrace(s, result, tmpVec, i + 1, endPos);
          tmpVec.pop_back();
        }
      }
    }
  }

  bool isPalindrome(const string &s, int startPos, int splitPos) {
    int i = startPos;
    int j = splitPos;
    while (i <= j) {
      if (s[i] == s[j]) {
        i++;
        j--;
      } else {
        return false;
      }
    }
    return true;
  }
};

