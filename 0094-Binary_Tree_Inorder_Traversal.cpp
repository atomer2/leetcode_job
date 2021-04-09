#include <iostream>
#include <stack>
#include <vector>

#include "utils.h"

using namespace std;

class Solution {
public:
  // clean solution learn from others.
  vector<int> inorderTraversal(TreeNode *root) {
    stack<TreeNode *> s;
    vector<int> res;
    TreeNode *pCurr = root;
    while (pCurr || !s.empty()) {
      while (pCurr) {
        s.push(pCurr);
        pCurr = pCurr->left;
      }
      pCurr = s.top();
      s.pop();
      res.push_back(pCurr->val);
      pCurr = pCurr->right;
    }
    return res;
  }
};

int main() { return 0; }
