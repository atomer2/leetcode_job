#include <algorithm>
#include <iostream>
#include <limits.h>
#include <queue>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>

#include "utils.h"

using namespace std;

class MedianFinder {
public:
  /** initialize your data structure here. */
  MedianFinder() {}

  void addNum(int num) {
    q1.push(num);
    q2.push(q1.top());
    q1.pop();
    if(q2.size() > q1.size()+1){
      q1.push(q2.top());
      q2.pop();
    }
  }

  double findMedian() {
    double r;
    if (q1.size() == q2.size()) {
      r = (q1.top() + q2.top()) / 2.0;
    } else {
      r = q2.top();
    }
    return r;
  }

  priority_queue<int, vector<int>, less<int>> q1;
  priority_queue<int, vector<int>, greater<int>> q2;
};
int main() { return 0; }
