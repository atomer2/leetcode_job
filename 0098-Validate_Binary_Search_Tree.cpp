#include <iostream>
#include <stack>
#include <climits>
#include "utils.h"

using namespace std;

// inorder travesal
class Solution {
 public:
  bool isValidBST(TreeNode* root) {
    stack<TreeNode*> s;
    int min;
    bool searchRight = false;
    bool firstPop = true;
    if (root == nullptr)
      return true;
    s.push(root);
    while (!s.empty()) {
      auto* currNode = s.top();
      if (searchRight) {
        s.pop();
        if (firstPop) {
          firstPop = false;
          min = currNode->val;
        } else if (currNode->val > min) {
          min = currNode->val;
        } else {
          return false;
        }
        if (currNode->right) {
          s.push(currNode->right);
          searchRight = false;
        }
      } else {
        if (currNode->left) {
          s.push(currNode->left);
        } else {
          searchRight = true;
        }
      }
    }
    return true;
  }
};
