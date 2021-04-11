#include <algorithm>
#include <iostream>
#include <limits.h>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>

#include "utils.h"

using namespace std;

class Solution {
public:
  bool isSymmetric(TreeNode *root) {
    return isSymm(root, root);
  }

  bool isSymm(TreeNode *lhs, TreeNode *rhs) {
    if (lhs == nullptr && rhs == nullptr)
      return true;
    else if (lhs == nullptr || rhs == nullptr)
      return false;

    if (lhs->val != rhs->val)
      return false;

    return isSymm(lhs->left, rhs->right) && isSymm(lhs->right, rhs->left);
  }
};

int main() { return 0; }
