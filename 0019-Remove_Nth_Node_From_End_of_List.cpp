class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode *first = dummy;
        ListNode *second = dummy;
        for(int i=0; i<n; ++i){
            second = second->next;
        }
        while(second->next != NULL){
            first = first->next;
            second = second->next;
        }
        first->next = first->next->next;
        return dummy->next;
    }
};
