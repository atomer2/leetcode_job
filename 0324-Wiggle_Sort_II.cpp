#include <limits.h>
#include <algorithm>
#include <iostream>
#include <iterator>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>

#include "utils.h"

using namespace std;

class Solution {
 public:
  // This is just too hard.
  void wiggleSort(vector<int>& nums) {
    size_t n = nums.size();
    auto imid = nums.begin() + n / 2;
    nth_element(nums.begin(), imid, nums.end());

    // genius.
    // remap position.
#define A(i) nums[(2 * (i) + 1) % (n | 1)]

    int midVal = *imid;
    int i = 0, j = 0, k = n - 1;

    /*   |     i   j  k        |
     *   | ****++++xxxx&&&&&&  |
     *   * - bigger than midVal
     *   + - equal midVal
     *   & - smaller than midVal
     *   + - not processed yet
     */
    while (j <= k) {
      if (A(j) > midVal) {
        swap(A(j++), A(i++));
      } else if (A(j) < midVal) {
        swap(A(j), A(k--));
      } else {
        j++;
      }
    }
  }
};

int main() {
  vector<int> input = {2, 1};
  Solution sln;
  sln.wiggleSort(input);
  std::copy(input.begin(), input.end(), ostream_iterator<int>(cout, " "));
  return 0;
}
