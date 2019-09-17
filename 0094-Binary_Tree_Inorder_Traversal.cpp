#include <iostream>
#include <vector>
#include <stack>

using namespace std;
struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
 public:
  vector<int> inorderTraversal(TreeNode* root) {
    stack<TreeNode*> s;
    vector<int> result;
    bool findRight = false;
    s.push(root);
    while (!s.empty()) {
      auto top = s.top();
      if (findRight) {
        s.pop();
        result.push_back(top->val);
        if (top->right) {
          s.push(top->right);
          findRight = false;
        }
      } else {
        if (top->left) {
          s.push(top->left);
        } else {
          findRight = true;
        }
      }
    }
    return result;
  }
};

int main() {
  return 0;
}
