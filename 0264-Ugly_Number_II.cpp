#include <limits.h>
#include <algorithm>
#include <iostream>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>

#include "utils.h"

using namespace std;
/* We have an array k of first n ugly number. We only know, at the beginning,
 * the first one, which is 1. Then
 *
 * k[1] = min( k[0]x2, k[0]x3, k[0]x5). The answer is k[0]x2. So we move 2's
 * pointer to 1. Then we test:
 *
 * k[2] = min( k[1]x2, k[0]x3, k[0]x5). And so on. Be careful about the cases
 * such as 6, in which we need to forward both pointers of 2 and 3.
 */

class Solution {
 public:
  // Very hard.
  int nthUglyNumber(int n) {
    if (n <= 0)
      return false;
    if (n == 1)
      return true;
    int t2 = 0, t3 = 0, t5 = 0;
    vector<int> k(n);
    k[0] = 1;
    for (int i = 1; i < n; i++) {
      k[i] = min(k[t2] * 2, min(k[t3] * 3, k[t5] * 5));
      if (k[i] == k[t2] * 2)
        t2++;
      if (k[i] == k[t3] * 3)
        t3++;
      if (k[i] == k[t5] * 5)
        t5++;
    }
    return k[n - 1];
  }
};

int main() {
  return 0;
}
