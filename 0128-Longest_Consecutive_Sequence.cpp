class Solution {
public:
  int longestConsecutive(vector<int> &nums) {
    unordered_set<int> numSet;
    for (int e : nums)
      numSet.insert(e);

    int length = 0;
    for (int e : numSet) {
      if (numSet.find(e - 1) == numSet.end()) {
        int tmp = 1;
        while (numSet.find(++e) != numSet.end())
          tmp++;
        if (tmp > length)
          length = tmp;
      }
    }
    return length;
  }
};

