#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

#include "utils.h"

using namespace std;

class Solution {
public:
  vector<string> generateParenthesis(int n){
    vector<string> ret;
    string str;
    backtrack(ret, str, n, n);
    return ret;
  }

  // Classic backtracking.
  void backtrack(vector<string> &ret, string &str, int leftRemain,
      int rightRemain) {
    if(leftRemain ==  0 && rightRemain == 0)
    {
      ret.push_back(str);
      return;
    }

    if(leftRemain > 0){
      str.push_back('(');
      backtrack(ret, str, leftRemain-1, rightRemain);
      str.pop_back();
    }

    if(rightRemain > leftRemain){
      str.push_back(')');
      backtrack(ret, str, leftRemain, rightRemain-1);
      str.pop_back();
    }
  }
};

int main() { 
  return 0; 
}
