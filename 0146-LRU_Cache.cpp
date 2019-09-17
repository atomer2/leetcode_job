#include <iostream>
#include <unordered_map>
using namespace std;

class LRUCache {
 public:
  typedef struct Dlist {
    Dlist* pre = nullptr;
    Dlist* next = nullptr;
    int val;
    int key;
  } Dlist;

  LRUCache(int capacity) {
    count = 0;
    cap = capacity;
    head = new Dlist;
    tail = head;
    auto p = head;
    for (int i = 0; i < cap; ++i) {
      auto node = new Dlist;
      p->next = node;
      node->pre = p;
      p = node;
    }
  }

  ~LRUCache() {
    auto p = head;
    while (p) {
      auto tmp = p;
      p = p->next;
      delete tmp;
    }
  }

  int get(int key) {
    auto it = map.find(key);
    if (it == map.end())
      return -1;
    auto node = it->second;
    putFront(head, &tail, node);
    return node->val;
  }

  void put(int key, int value) {
    auto it = map.find(key);
    if (it != map.end()) {
      auto node = it->second;
      node->val = value;
      putFront(head, &tail, node);
    } else if (count == cap) {
      // remove
      map.erase(tail->key);
      tail->val = value;
      tail->key = key;
      map[key] = tail;
      putFront(head, &tail, tail);
    } else {
      tail = tail->next;
      tail->val = value;
      tail->key = key;
      map[key] = tail;
      count++;
      putFront(head, &tail, tail);
    }
  }

  void putFront(Dlist* head, Dlist** tail, Dlist* node) {
    if (node == head->next)
      return;
    if (*tail == node) {
      *tail = node->pre;
    }
    node->pre->next = node->next;
    if (node->next)
      node->next->pre = node->pre;
    node->next = head->next;
    head->next->pre = node;
    node->pre = head;
    head->next = node;
  }

 private:
  Dlist* head;
  Dlist* tail;
  int count;
  int cap;
  unordered_map<int, Dlist*> map;
};

int main() {
  LRUCache cache(2);
  cache.put(1, 1);
  cache.put(2, 2);
  cache.get(1);
  cache.put(3, 3);
  cout << cache.get(2) << endl;
  system("pause");
  return 0;
}