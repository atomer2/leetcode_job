#include <vector>
#include <stack>

#include "utils.h"

using namespace std;

class Solution {
 public:
  bool hasPathSum(TreeNode* root, int sum) {
    if (root == nullptr) {
      if (sum == 0)
        return true;
      else
        return false;
    }
    return hasPathSum(root->left, sum - root->val) ||
           hasPathSum(root->right, sum - root->val);
  }
};
