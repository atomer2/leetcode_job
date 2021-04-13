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
  int kthSmallest(TreeNode *root, int k) {
    vector<TreeNode *> stk;
    TreeNode *curr = root;
    while (curr || !stk.empty()) {
      while (curr) {
        stk.push_back(curr);
        curr = curr->left;
      }
      auto *node = stk.back();
      stk.pop_back();
      if(--k == 0)
        return node->val;
      curr = node->right;
    }
    return 0;
  }
};

int main() { return 0; }
