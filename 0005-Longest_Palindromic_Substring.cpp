#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Manacher method, O(N)
class Solution {
 public:
  string longestPalindrome(string s) {
    int pR = 0, index = 0;
    int new_size = s.size() * 2 + 1;
    vector<int> rvec(new_size, 0);

    string s1 = string(new_size, ' ');
    for (int i = 0; i < new_size; ++i) {
      s1[i] = i % 2 ? s[i / 2] : '#';
    }
    for (int i = 0; i < new_size; ++i) {
      if (i < pR) {
        int i_m = index * 2 - i;
        int left_small = i_m - rvec[i_m] + 1;
        int right_small = i_m + rvec[i_m] - 1;
        int left_big = index - rvec[index] + 1;
        int right_big = index + rvec[index] - 1;
        if (left_big < left_small) {
          rvec[i] = rvec[i_m];
        } else if (left_big > left_small) {
          rvec[i] = i_m - left_big + 1;
        } else {
          int p = right_big + 1;
          while (p < new_size && 2 * i - p >= 0 && s1[p] == s1[2 * i - p]) {
            p++;
          }
          rvec[i] = p - i;
          index = i;
          pR = p;
        }
      } else {
        int p = i + 1;
        while (p < new_size && 2 * i - p >= 0 && s1[p] == s1[2 * i - p]) {
          p++;
        }
        rvec[i] = p - i;
        index = i;
        pR = p;
      }
    }
    int max_mid = -1;
    int max_r = -1;
    for (int i = 0; i < new_size; ++i) {
      if (rvec[i] > max_r) {
        max_mid = i;
        max_r = rvec[i];
      }
    }
    int len = max_r - 1;
    string res(len, ' ');
    int j = 0;
    for (int i = max_mid - max_r + 1; i < max_mid + max_r - 1; i++) {
      if (s1[i] != '#') {
        res[j] = s1[i];
        j++;
      }
    }
    return res;
  }
};

int main() {
  Solution solution;
  string s = "babadada";
  cout << solution.longestPalindrome(s) << endl;
  system("pause");
}