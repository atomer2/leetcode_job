// My solution
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* root = new ListNode(0);
        root->next = head;
        auto pre = root;
        auto p = root;
        while(p && p->next){
            auto s = p->next;
            if(p->next->val < x){
                auto next = p->next;
                p->next = p->next->next;
                next->next = pre->next;
                pre->next = next;
                pre = pre->next;
            }
            if(s == p->next)
                p = p->next;
        }
        auto res = root->next;
        delete root;
        return res;
    }
}
