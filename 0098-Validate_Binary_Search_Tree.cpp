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
  // If we use in-order traversal to serialize a binary search tree, we can get
  // a list of values in ascending order. It can be proved with the definition
  // of the BST. And here I use the reference of the TreeNode pointer `prev` as
  // a global variable to mark the address of previous node in the list.
  bool isValidBST(TreeNode *root) {
    TreeNode* prev = nullptr;
    return validate(root, prev);
  }

  bool validate(TreeNode* node, TreeNode* prev){
    if(!node) return true;
    if(!validate(node->left, prev)) return false;
    if(prev && prev->val >= node->val) return false;
    prev = node;
    return validate(node->right, prev);
  }

};

int main() { return 0; }
