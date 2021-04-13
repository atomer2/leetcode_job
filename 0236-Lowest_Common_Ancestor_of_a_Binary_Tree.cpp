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
  // Clever solution.
  TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
    if (root == nullptr || root == p || root == q)
      return root;

    auto *left = lowestCommonAncestor(root->left, p, q);
    auto *right = lowestCommonAncestor(root->right, p, q);

    if (!left)
      return right;
    if (!right)
      return left;
    return root;
  }
};

int main() { return 0; }
