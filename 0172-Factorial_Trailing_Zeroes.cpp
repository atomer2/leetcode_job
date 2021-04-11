#include <algorithm>
#include <iostream>
#include <limits.h>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>

#include "utils.h"

using namespace std;

class Solution {
public:
  int trailingZeroes(int n) {
    return n == 0 ? 0 : n / 5 + trailingZeroes(n / 5);
  }
};

int main() { return 0; }
