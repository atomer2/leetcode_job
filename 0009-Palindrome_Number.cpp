#include <iostream>
#include <numeric>

using namespace std;

class Solution {
 public:
  bool isPalindrome(int x) {
    if (x < 0)
      return false;
    if (x < 10)
      return true;
    int n = 1000000000;
    while (n > x)
      n /= 10;
    int i = 10;
    while (1) {
      int big_digit = x / n;   
      int small_digit = x % i;
      small_digit = small_digit / (i / 10);
      x = x - big_digit * n;
      if (big_digit != small_digit)
        return false;
      i = i * 10;
      n = n / 10;
      if (i > n)
        break;
    }
    return true;
  }
};

int main() {
  Solution solution;
  cout << solution.isPalindrome(12345321) << endl;
  system("pause");
}