#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

#include "utils.h"

using namespace std;

class Solution {
public:
  int maxSubArray(vector<int>& nums){
    if(nums.empty())
      return 0;
    int ret = nums[0];

    for(int i=1; i<nums.size(); i++){
      if(nums[i] + nums[i-1] > nums[i]){
        nums[i] += nums[i-1];
      }
      ret = max(nums[i], ret);
    }
    return ret;
  }
};

int main() { 
  return 0; 
}
