#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// An elegant DP solution learn from others
class Solution {
 public:
  vector<TreeNode*> generateTrees(int n) {
    vector<vector<TreeNode*>> table(n + 1);
    if (n == 0)
      return table[0];
    table[0].push_back(nullptr);
    for (int i = 1; i <= n; ++i) {
      for (int k = 0; k < i; ++k) {
        for (auto leftNode : table[k]) {
          for (auto rightNode : table[i - k - 1]) {
            TreeNode* root = new TreeNode(k + 1);
            root->left = leftNode;
            root->right = cloneTree(rightNode, k + 1);
            table[i].push_back(root);
          }
        }
      }
    }
    return table[n];
  }

  TreeNode* cloneTree(TreeNode* node, int offset) {
    if (node == nullptr) {
      return nullptr;
    }
    TreeNode* root = new TreeNode(node->val + offset);
    root->left = cloneTree(node->left, offset);
    root->right = cloneTree(node->right, offset);
    return root;
  }
};
