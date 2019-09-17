// ugly solution :-(
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == nullptr)
            return head;
        ListNode *root = new ListNode(0);
        root->next = head;
        auto p = root;
        auto pre = root;
        int lastVal = head->val + 1;
        int count = 1;
        while(p->next){
            if(p->next->val == lastVal){
                p = p->next;
                count++;
            }else{
                lastVal = p->next->val;
                if(count != 1){
                    auto pr = pre->next;
                    pre->next = p->next;
                    p = p->next;
                    for(int i=0; i<count; i++){
                        auto tmp = pr;
                        pr = pr->next;
                        delete tmp;                       
                    }             
                }else{
                    pre = p;
                    p = p->next;
                }
                count = 1;
            }
        }
        if(count != 1){
            auto pr = pre->next;
            pre->next = p->next;
            for(int i=0; i<count; i++){
                auto tmp = pr;
                pr = pr->next;
                delete tmp;                       
            }             

        }
        auto res = root->next;
        delete root;
        return res;
    }
};
