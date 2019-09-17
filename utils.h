#ifndef LEETCODE_UTILS_H__
#define LEETCODE_UTILS_H__

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
#endif
