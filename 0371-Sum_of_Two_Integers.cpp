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
  int getSum(int a, int b) {
    // we must use unsigned type, or the left shift will cause problem.
    uint sum = a ^ b;
    uint carry = a & b;
    while (carry) {
      carry <<= 1;
      uint save_carry = carry;
      carry = sum & carry;
      sum = sum ^ save_carry;
    }
    return (int)sum;
  }
};

int main() { return 0; }
