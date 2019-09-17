/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() {}

    Node(int _val, Node* _left, Node* _right, Node* _next) {
        val = _val;
        left = _left;
        right = _right;
        next = _next;
    }
};
*/
// My solution
class Solution {
public:
    Node* connect(Node* root) {
        if(!root || !root->left)
            return root;

        auto* left = connect(root->left);
        auto* right = connect(root->right);

        left->next = right;
        while(left->right){
            left->right->next = right->left;
            left = left->right;
            right = right->left;
        }
        return root;
    }
};
