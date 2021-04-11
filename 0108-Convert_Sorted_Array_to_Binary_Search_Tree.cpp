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
  TreeNode* sortedArrayToBST(vector<int>& nums){
    int n = nums.size();
    return buildTree(nums, 0, n-1);
  }

  TreeNode* buildTree(vector<int>& nums, int l, int r){
    if(l > r) return nullptr;
    if(l == r){
      return new TreeNode(nums[l]);
    }

    int mid = l + ((r-l) >> 1);
    TreeNode* pr = new TreeNode(nums[mid]);
    pr->left = buildTree(nums, l, mid-1);
    pr->right = buildTree(nums, mid+1, r);
    return pr;
  }
};

int main() { 
  return 0; 
}
