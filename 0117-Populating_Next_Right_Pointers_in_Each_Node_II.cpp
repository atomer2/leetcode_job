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
        if(!root)
            return nullptr;
        auto* lhs = connect(root->left);
        auto* rhs = connect(root->right);
        do{
            if(!lhs || !rhs)
                break;
            auto* lrm = lhs;
            while(lrm->next)
                lrm = lrm->next;
            lhs = getNextLeftMost(lhs);
            // DO NOT change order!!
            lrm->next = rhs;
            rhs = getNextLeftMost(rhs);

        }while(true);

        return root;
    }

    Node* getNextLeftMost(Node* root){
        if(root->left)
            return root->left;
        if(root->right)
            return root->right;
        if(root->next)
            return getNextLeftMost(root->next);
        return nullptr;
    }
};
