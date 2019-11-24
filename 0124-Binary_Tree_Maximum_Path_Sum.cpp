/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// DFS
class Solution {
public:
    int maxPathSum(TreeNode* root) {
        int currMax = INT_MIN;
        maxPathSumRecursive(root, &currMax);
        return currMax;        
    }
    
    int maxPathSumRecursive(TreeNode* root, int *currMax){
        if(root == NULL)
            return 0;
        int leftMax = maxPathSumRecursive(root->left, currMax);
        int rightMax = maxPathSumRecursive(root->right, currMax);
        
        int res = root->val + max(max(leftMax, rightMax), 0);
        int tmpMax = root->val;
        tmpMax += max(leftMax, 0);
        tmpMax += max(rightMax, 0);
        if(tmpMax > *currMax)
            *currMax = tmpMax;
        return res;
    }
};
