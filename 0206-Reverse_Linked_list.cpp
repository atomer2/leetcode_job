#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <stack>
#include <limits.h>

#include "utils.h"

using namespace std;

class Solution {
public:
  ListNode* reverseList(ListNode* head){
    ListNode dummy, *p = head;
    while(p){
      ListNode* next = p->next;
      p->next = dummy.next;
      dummy.next = p;
      p = next;
    }
    return dummy.next;
  }
};

int main() { 
  return 0; 
}
