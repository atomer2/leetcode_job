#include <iostream>
#include <vector>
#include <deque>
#include "utils.h"

using namespace std;

class Solution {
 public:
  vector<vector<int>> levelOrder(TreeNode* root) {
    deque<TreeNode*> q;
    vector<vector<int>> result;

    if (root == nullptr)
      return result;

    vector<int> ivec;
    int level_cnt = 1;
    int nextCount = 0;
    q.push_back(root);
    while (!q.empty()) {
      auto node = q.front();
      q.pop_front();
      ivec.push_back(node->val);
      if (node->left) {
        q.push_back(node->left);
        nextCount++;
      }
      if (node->right) {
        q.push_back(node->right);
        nextCount++;
      }
      if (--level_cnt == 0) {
        level_cnt = nextCount;
        nextCount = 0;
        result.push_back(ivec);
        ivec.clear();
      }
    }
    return result;
  }
};
