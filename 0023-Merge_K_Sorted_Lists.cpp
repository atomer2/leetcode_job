#include <functional>
#include <iostream>
#include <memory>
#include <queue>
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

struct ListDeleter {
  void operator()(ListNode* l) {
    ListNode* tmp;
    while (l) {
      tmp = l->next;
      delete l;
      l = tmp;
    }
  }
};

void PrintList(ListNode* l) {
  while (l) {
    cout << l->val;
    if (l->next)
      cout << "->";
    l = l->next;
  }
}
}  // namespace

/*** Suppose list length is N, Time Complexity O(NlgK) Space Complexity O(K)
class Solution {
 public:
  // min heap
  ListNode* mergeKLists(vector<ListNode*>& lists) {
    priority_queue<ListNode*, vector<ListNode*>, MyComp> q;
    auto head = make_unique<ListNode>(0);
    auto ph = head.get();
    for (auto list : lists) {
      q.push(list);
    }
    while (!q.empty()) {
      ListNode* top = q.top();
      q.pop();
      ph->next = top;
      ph = top;
      if (top->next) {
        q.push(top->next);
        top->next = NULL;
      }
    }
    return head->next;
  }

 private:
  struct MyComp {
    bool operator()(ListNode* lhs, ListNode* rhs) {
      return lhs->val > rhs->val;
    }
  };
};
***/

class Solution {
 public:
  // divide and conquer
  ListNode* mergeKLists(vector<ListNode*>& lists) {
    auto lsize = lists.size();
    int stride = 2;
    int near = 1;
    while (true) {
      int pivot = 0;
      while (pivot < lsize && pivot + near < lsize) {
        mergeTwoList(&lists[pivot], &lists[pivot + near]);
        pivot = pivot + stride;
      }
      if (pivot == 0)
        break;
      stride = stride << 1;
      near = near << 1;
    }
    return lists[0];
  }

 private:
  // merget two list to llst
  void mergeTwoList(ListNode** llst, ListNode** rlst) {
    if (*llst == NULL)
      swap(*llst, *rlst);
    if (*rlst == NULL)
      return;

    if ((*llst)->val > (*rlst)->val) {
      swap(*llst, *rlst);
    }
    ListNode* head = *llst;
    ListNode* p = head;
    ListNode* lhead = head->next;
    ListNode* rhead = *rlst;
    while (lhead != NULL && rhead != NULL) {
      if (lhead->val < rhead->val) {
        p->next = lhead;
        p = lhead;
        lhead = lhead->next;
        p->next = NULL;
      } else {
        p->next = rhead;
        p = rhead;
        rhead = rhead->next;
        p->next = NULL;
      }
    }
    if (lhead == NULL)
      p->next = rhead;
    else if (rhead == NULL)
      p->next = lhead;
  }
};

int main() {
  vector<ListNode*> inputs;
  vector<int> l1v{1, 4, 5};
  vector<int> l2v{1, 3, 4};
  vector<int> l3v{2, 6};

  std::unique_ptr<ListNode, ListDeleter> pResList;

  inputs.push_back(BuildListFromVector(l1v));
  inputs.push_back(BuildListFromVector(l2v));
  inputs.push_back(BuildListFromVector(l3v));

  Solution solution;
  pResList.reset(solution.mergeKLists(inputs));
  PrintList(pResList.get());
  system("pause");
  return 0;
}