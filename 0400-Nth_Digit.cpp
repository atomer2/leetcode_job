#include <bits/stdc++.h>
#include "utils.h"

using namespace std;

// clever solution learn from others.
class Solution {
 public:
  int findNthDigit(int n) {
    int len = 1;
    long count = 9;
    int start = 1;
    while (n > len * count) {
      n -= len * count;
      len += 1;
      count *= 10;
      start *= 10;
    }

    start += (n - 1) / len;
    string s = to_string(start);
    return int(s[(n - 1) %len] - '0');
  }
};

int main(int argc, char **argv) {
  if(argc < 2){
    std::cout << "please input n" << std::endl;
    return 0;
  }

  int n = atoi(argv[1]);
  Solution sln;
  int res = sln.findNthDigit(n);

  cout << "result is " <<  res << std::endl;

  return 0;
}
