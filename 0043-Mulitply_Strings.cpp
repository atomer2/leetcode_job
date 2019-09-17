#include <iostream>
#include <memory>
#include <string>

using namespace std;
class Solution {
 public:
  string multiply(string num1, string num2) {
    if (num1 == "0" || num2 == "0")
      return string("0");
    char res[221];
    int ssi[110];
    int lsi[110];
    memset(res, 0, sizeof(res));
    string& ss = num1.size() < num2.size() ? num1 : num2;
    string& ls = num1.size() < num2.size() ? num2 : num1;
    for (int i = 0; i < ss.size(); ++i) {
      ssi[i] = ss[ss.size() - i - 1] - '0';
    }
    for (int i = 0; i < ls.size(); ++i) {
      lsi[i] = ls[ls.size() - i - 1] - '0';
    }
    int carry = 0;
    for (int i = 0; i < ss.size(); ++i) {
      carry = 0;
      int j;
      for (j = 0; j < ls.size(); ++j) {
        // multiply
        int val = lsi[j] * ssi[i] + carry + res[j + i];
        res[i + j] = val % 10;
        carry = val / 10;
      }
      if (carry != 0)
        res[j + i] = carry;
    }

    int outlen = ss.size() + ls.size() - (carry > 0 ? 0 : 1);
    char res2[221];
    for (int i = 0; i < outlen; ++i) {
      res2[i] = res[outlen - i -1] + '0';
    }
    res2[outlen] = '\0';
    string s(res2);
    return s;
  }
};

int main() {
  Solution s;
  string num1("123");
  string num2("456");
  
  cout << s.multiply(num1, num2) << endl;
  system("pause");
}