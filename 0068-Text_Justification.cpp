#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
 public:
  vector<string> fullJustify(vector<string>& words, int maxWidth) {
    int pos = -1;
    vector<string> res;
    vector<string> temp;
    for (const auto& w : words) {
      pos += w.size() + 1;
      if (pos == maxWidth) {
        string s;
        for (const auto& iw : temp) {
          s = s + iw + " ";
        }
        s += w;
        pos = -1;
        res.push_back(s);
        temp.clear();
      } else if (pos > maxWidth) {
        int extraSpace = (maxWidth - (pos - w.size() - 1));
        if (temp.size() == 1) {
          auto s = temp.back();
          for (int i = 0; i < extraSpace; ++i)
            s += " ";
          res.push_back(s);
          temp.clear();
          temp.push_back(w);
          pos = w.size();
        } else {
          int b = extraSpace / (temp.size() - 1);
          int s = extraSpace % (temp.size() - 1);
          string str;
          for (int i = 0; i < s; i++) {
            str += temp[i];
            for (int j = 0; j <= b + 1; j++) {
              str += " ";
            }
          }
          for (size_t i = s; i < temp.size() - 1; ++i) {
            str += temp[i];
            for (int j = 0; j <= b; j++) {
              str += " ";
            }
          }
          str += temp.back();
          res.push_back(str);
          temp.clear();
          temp.push_back(w);
          pos = w.size();
        }
      } else {
        temp.push_back(w);
      }
    }
    if (!temp.empty()) {
      string str;
      for (size_t i = 0; i < temp.size() - 1; i++) {
        str += temp[i] + " ";
      }
      str += temp.back();
      int gap = maxWidth - str.size();
      for (int i = 0; i < gap; ++i) {
        str += " ";
      }
      res.push_back(str);
    }
    return res;
  }
};

int main() {
  vector<string> input{"This",          "is", "an", "example", "of", "text",
                       "justification."};
  vector<string> input2{"What", "must", "be", "acknowledgment", "shall", "be"};
  Solution solution;
  auto output = solution.fullJustify(input2, 16);
  for (auto& e : output) {
    cout << e << endl;
  }
  return 0;
}
