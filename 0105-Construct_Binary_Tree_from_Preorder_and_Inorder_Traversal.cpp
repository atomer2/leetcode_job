#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>

#include "utils.h"

using namespace std;

class Solution {
 public:
  TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    return buildTreeRecursive(preorder.begin(), preorder.end(), inorder.begin(),
                              inorder.end());
  }

  using iterator = vector<int>::iterator;
  TreeNode* buildTreeRecursive(iterator p0,
                               iterator p1,
                               iterator i0,
                               iterator i1) {
    if (i0 == i1)
      return nullptr;
    auto it = find(i0, i1, *p0);
    auto node = new TreeNode(*it);
    auto pm = next(p0);
    advance(pm, distance(i0, it));
    node->left = buildTreeRecursive(next(p0), pm, i0, it);
    node->right = buildTreeRecursive(pm, p1, next(it), i1);
    return node;
  }
};
