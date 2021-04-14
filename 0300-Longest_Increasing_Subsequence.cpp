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
  int lengthOfLIS(vector<int> &nums){
    vector<int> seq;
    for(int i=0; i<nums.size(); i++){
      if(i==0 || nums[i] > seq.back())
        seq.push_back(nums[i]);
      else{
        auto it = lower_bound(seq.begin(), seq.end(), nums[i]);
        *it = nums[i];
      }
    }
    return seq.size();
  }
};

int main() { 
  return 0; 
}
