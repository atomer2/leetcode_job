class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {      
        ListNode* root = new ListNode(0);
        root->next = head;

        ListNode* p = root;
        for(int i=0; i<m-1; ++i){
            p = p->next;          
        }
        // Don't worry, pre is not nullptr
        ListNode* pre = p->next;
        ListNode* start = p->next;
        ListNode* curr = pre->next;
        for(int i=0; i< n-m; ++i){
            ListNode* temp = curr->next;
            curr->next = pre;
            pre = curr;
            curr = temp;
        }
        p->next = pre;
        start->next = curr;

        auto* res = root->next;
        delete root;
        return res;
    }
};
