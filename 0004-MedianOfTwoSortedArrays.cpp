#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  Solution() = default;

  double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    const vector<int>& m_SmallArr = nums1.size() < nums2.size() ? nums1 : nums2;
    const vector<int>& m_BigArr = nums1.size() >= nums2.size() ? nums1 : nums2;
    if (m_SmallArr.size() == 0) {
      int mid_index = m_BigArr.size() / 2;
      if (m_BigArr.size() % 2 == 0)
        return (m_BigArr[mid_index] + m_BigArr[mid_index - 1]) / 2.0f;
      else
        return m_BigArr[mid_index];
    }
    int p = -1;
    int q = m_SmallArr.size() - 1;
    bool bOddSize = (nums1.size() + nums2.size()) % 2;
    int res_j;
    do {
      if (p == q) {
        res_j = p;
        break;
      }
      int mid = (p + q) / 2;
      int rv = isMedian(mid, m_SmallArr, m_BigArr);
      if (!rv) {
        res_j = mid;
        break;
      }
      if (rv == 1)
        p = mid + 1;
      if (rv == 2)
        q = mid - 1;
    } while (1);
    int res_i = (m_SmallArr.size() + m_BigArr.size()) / 2 - res_j - 2;
    int n1 = res_j == -1 ? std::numeric_limits<int>::min() : m_SmallArr[res_j];
    int n2 = res_i == -1 ? std::numeric_limits<int>::min() : m_BigArr[res_i];
    int n3 = res_j == m_SmallArr.size() - 1 ? std::numeric_limits<int>::max()
                                            : m_SmallArr[res_j + 1];
    int n4 = res_i == m_BigArr.size() - 1 ? std::numeric_limits<int>::max()
                                          : m_BigArr[res_i + 1];
    int up_median = min(n3, n4);
    int low_median = max(n1, n2);

    return bOddSize ? up_median : (up_median + low_median) / 2.0f;
  }

 private:
  int isMedian(int j,
               const vector<int>& m_SmallArr,
               const vector<int>& m_BigArr) {
    int i = (m_SmallArr.size() + m_BigArr.size()) / 2 - j - 2;
    int n1 = j == -1 ? std::numeric_limits<int>::min() : m_SmallArr[j];
    int n2 = i == -1 ? std::numeric_limits<int>::min() : m_BigArr[i];
    int n3 = j == m_SmallArr.size() - 1 ? std::numeric_limits<int>::max()
                                            : m_SmallArr[j + 1];
    int n4 = i == m_BigArr.size() - 1 ? std::numeric_limits<int>::max()
                                          : m_BigArr[i + 1];
    if (n1 <= n4 && n2 <= n3)
      return 0;
    if (n2 > n3)
      return 1;
    if (n1 > n4)
      return 2;
	
    return 3;
  }
};

int main() {
  Solution solution;
  vector<int> nums1 = {1};
  vector<int> nums2={1};
  cout << solution.findMedianSortedArrays(nums1, nums2) << endl;
  system("pause");
}