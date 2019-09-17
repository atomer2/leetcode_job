#include <iostream>
#include <memory>
#include <vector>

using namespace std;

namespace {
struct ListNode {
  int val;
  ListNode* next;
  ListNode(int x) : val(x), next(NULL) {}
};

ListNode* BuildListFromVector(vector<int> vec) {
  auto dummy = make_unique<ListNode>(0);
  auto pos = dummy.get();
  for (auto v : vec) {
    auto node = new ListNode(v);
    pos->next = node;
    pos = node;
  }
  return dummy->next;
}

void DeleteList(ListNode* l) {
  ListNode* tmp;
  while (l) {
    tmp = l->next;
    delete l;
    l = tmp;
  }
}

void PrintList(ListNode* l) {
  while (l) {
    cout << l->val;
    if (l->next)
      cout << "->";
    l = l->next;
  }
}
}  // namespace

class Solution {
 public:
  /* not exactly right, but I think it's elegant
  /*
  ListNode* reverseKGroup(ListNode* head, int k) {
    ListNode* dummy = new ListNode(0);
    dummy->next = head;
    ListNode* head1 = dummy;
    ListNode* head2 = head;
    ListNode* p = head;
    ListNode* temp;
    while (p) {
      ListNode* pre = NULL;
      int c = k;
      while (p && c-- > 0) {
        temp = p->next;
        p->next = pre;
        pre = p;
        p = temp;
      }
      head1->next = pre;
      head1 = head2;
      head2 = p;
    }
    ListNode* res = dummy->next;
    delete dummy;
    return res;
  }
  */
  ListNode* reverseKGroup(ListNode* head, int k) {
    int n = 0;
    auto pos = head;
    while (pos) {
      n++;
      pos = pos->next;
    }
    int groups = n / k;
    ListNode* dummy = new ListNode(0);
    ListNode* head1 = dummy;
    ListNode* head2 = head;
    ListNode* p = head;
    ListNode* temp;
    for (int i = 0; i < groups; ++i) {
      ListNode* pre = NULL;
      int c = k;
      while (c-- > 0) {
        temp = p->next;
        p->next = pre;
        pre = p;
        p = temp;
      }
      head1->next = pre;
      head1 = head2;
      head2 = p;
    }
    if (groups * k < n) {
      head1->next = head2;
    }
    ListNode* res = dummy->next;
    delete dummy;
    return res;
  }
};

int main() {
  Solution S;
  vector<int> arr{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
  ListNode* l = BuildListFromVector(arr);
  ListNode* rl = S.reverseKGroup(l,3);
  PrintList(rl);
  DeleteList(rl);
  system("pause");
}