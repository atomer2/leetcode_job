#include <iostream>
#include <deque>
#include "utils.h"

using namespace std;

class Solution {
 public:
  bool btreeGameWinningMove(TreeNode* root, int n, int x) {
    // get x node
    auto* xnode = getXNode(root, x);
    int leftTreeCount = getNodeNum(xnode->left);
    int rightTreeCount = getNodeNum(xnode->right);
    int pCount = n - leftTreeCount - rightTreeCount - 1;
    if ((leftTreeCount + rightTreeCount + 1) < pCount ||
        (leftTreeCount + pCount + 1) < rightTreeCount ||
        (rightTreeCount + pCount + 1) < leftTreeCount)
      return true;
    return false;
  }

  // preorder, get x node
  TreeNode* getXNode(TreeNode* root, int x) {
    deque<TreeNode*> q;
    q.push_back(root);
    while (!q.empty()) {
      auto node = q.front();
      q.pop_front();
      if (node->val == x)
        return node;
      if (node->left)
        q.push_back(node->left);
      if (node->right)
        q.push_back(node->right);
    }
    return nullptr;
  }

  int getNodeNum(TreeNode* root) {
    if (root == nullptr)
      return 0;
    return 1 + getNodeNum(root->left) + getNodeNum(root->right);
  }
};
