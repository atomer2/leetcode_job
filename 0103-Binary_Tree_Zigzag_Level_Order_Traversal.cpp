#include <iostream>
#include <vector>
#include <deque>
#include "utils.h"

using namespace std;

class Solution {
 public:
  vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    deque<TreeNode*> q;
    vector<vector<int>> result;
    vector<int> ivec;
    int count = 1;
    int nextCount = 0;
    bool bltr = true;
    if (root == nullptr)
      return result;

    q.push_back(root);
    while (!q.empty()) {
      if (bltr) {
        auto* node = q.front();
        ivec.push_back(node->val);
        q.pop_front();
        if (node->left) {
          q.push_back(node->left);
          nextCount++;
        }
        if (node->right) {
          q.push_back(node->right);
          nextCount++;
        }
      } else {
        auto* node = q.back();
        ivec.push_back(node->val);
        q.pop_back();
        if (node->right) {
          q.push_front(node->right);
          nextCount++;
        }
        if (node->left) {
          q.push_front(node->left);
          nextCount++;
        }
      }
      if (--count == 0) {
        count = nextCount;
        nextCount = 0;
        bltr = !bltr;
        result.push_back(ivec);
        ivec.clear();
      }
    }
    return result;
  }
};
