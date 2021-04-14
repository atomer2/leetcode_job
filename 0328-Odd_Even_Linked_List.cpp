#include <limits.h>
#include <algorithm>
#include <iostream>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>

#include "utils.h"

using namespace std;

class Solution {
 public:
  ListNode* oddEvenList(ListNode* head) {
    if (!head)
      return nullptr;
    ListNode odd, even, *pOdd, *pEven;
    odd.next = head;
    even.next = head->next;
    pOdd = head;
    pEven = head->next;
    while (pEven) {
      ListNode* next = pEven->next;
      if (next) {
        pOdd->next = next;
        pOdd = pOdd->next;
        pEven->next = next->next;
      }
      pEven = pEven->next;
    }

    pOdd->next = even.next;

    return odd.next;
  }
};

int main() {
  return 0;
}
