#include <limits.h>
#include <algorithm>
#include <iostream>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>

#include "utils.h"

using namespace std;

class Solution { public: // very clever, 1162261467 is the biggest number that is power of three you
  // can put in a int type.
  bool isPowerOfThree(int n) { return n <= 0 ? false : 1162261467 % n == 0; }
};

int main() {
  return 0;
}
