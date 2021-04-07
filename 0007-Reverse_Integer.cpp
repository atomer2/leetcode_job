#include <iostream>
#include <limits.h>
class Solution {
public:
  int reverse(int x) {
    // 注意int类型正负边界的不对称
    if (x == INT_MIN)
      return 0;
    int n = x < 0 ? -x : x;
    int res = 0;
    while (n) {
      int r = n % 10;
      n /= 10;
      if (res <= INT_MAX / 10) { // 是小于或者等于
        res *= 10;
        res += r;
        // 判断整型溢出
        if (res < r)
          return 0;
      } else {
        return 0;
      }
    }
    return x < 0 ? -n : n;
  }
};

