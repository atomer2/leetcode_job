#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
 public:
  vector<TreeNode*> generateTrees(int n) {
    vector<int> v(n, 0);
    vector<TreeNode*> result;
    auto* root = new TreeNode(-1);
    generateTreesRecursive(root, v, result, n);
    delete root;
    return result;
  }

  void generateTreesRecursive(TreeNode* root,
                              vector<int>& v,
                              vector<TreeNode*>& result,
                              int n) {
    int count = 0;
    for (int i = 0; i < n; i++) {
      if (v[i] == 0) {
        count++;
        v[i] = 1;
        auto* node = new TreeNode(i + 1);
        auto* parent = insertNode(root, node);
        generateTreesRecursive(root, v, result, n);
        if (parent->left == node)
          parent->left = nullptr;
        else
          parent->right = nullptr;
        v[i] = 0;
      }
    }
    if (count == 0) {
      result.push_back(root->right);
    }
  }

  TreeNode* insertNode(TreeNode* root, TreeNode* node) {
    while (root != nullptr) {
      if (node->val > root->val) {
        if (!root->right) {
          root->right = node;
          return root;
        }
        root = root->right;

      } else if (node->val < root->val) {
        if (!root->left) {
          root->left = node;
          return root;
        }
        root = root->left;
      }
    }
    return nullptr;
  };
};
