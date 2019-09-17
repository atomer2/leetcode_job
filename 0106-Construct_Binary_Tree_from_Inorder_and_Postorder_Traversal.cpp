#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>

#include "utils.h"

using namespace std;
class Solution {
 public:
  TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
    return buildTreeRecursive(inorder.begin(), inorder.end(),
                              postorder.rbegin(), postorder.rend());
  }

  using iterator = vector<int>::iterator;
  using riterator = vector<int>::reverse_iterator;
  TreeNode* buildTreeRecursive(const iterator& i0,
                               const iterator& i1,
                               const riterator& p0,
                               const riterator& p1) {
    if (i0 == i1)
      return nullptr;
    auto it = find(i0, i1, *p0);
    auto node = new TreeNode(*it);
    auto pm = p0;
    advance(pm, distance(it, i1));
    node->left = buildTreeRecursive(i0, it, pm, p1);
    node->right = buildTreeRecursive(next(it), i1, next(p0), pm);
    return node;
  }
};
