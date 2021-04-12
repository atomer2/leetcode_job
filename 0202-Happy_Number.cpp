#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <stack>
#include <limits.h>

#include "utils.h"

using namespace std;

class Solution {
public:
  // Clever solution learn from others.
  // Actually, we can simply adapt the Floyd Cycle detection algorithm.
  int digitSquareSum(int n){
    int sum = 0, tmp;
    while(n){
      tmp = n % 10;
      sum += tmp * tmp;
      n /= 10;
    }
    return sum;
  }

  bool isHappy(int n){
    int slow, fast;
    slow = fast = n;
    do{
      slow = digitSquareSum(slow);
      fast = digitSquareSum(fast);
      fast = digitSquareSum(fast);
    }while(slow != fast);
    
    return slow == 1;
  }
};

int main() { 
  return 0; 
}
