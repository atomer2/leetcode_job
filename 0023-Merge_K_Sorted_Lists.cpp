#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

#include "utils.h"

using namespace std;

class Solution {
public:
  ListNode *mergeKLists(vector<ListNode *> &lists) {
    vector<ListNode *> vl;
    ListNode dummy, *p = &dummy;

    for (auto &&list : lists) {
      // Be careful for border condition.
      if (list)
        vl.push_back(list);
    }
    auto cmp = [](const ListNode *lhs, const ListNode *rhs) {
      return lhs->val > rhs->val;
    };
    make_heap(begin(vl), end(vl), cmp);
    while (!vl.empty()) {
      // pop_heap put the top of the heap to the position of the last element.
      pop_heap(begin(vl), end(vl), cmp);
      ListNode *node = vl.back();
      vl.pop_back();
      p->next = node;
      p = p->next;
      if (p->next) {
        vl.push_back(p->next);
        push_heap(begin(vl), end(vl), cmp);
      }
    }
    return dummy.next;
  }
};

int main() { return 0; }
