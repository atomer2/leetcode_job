#include <iostream>
#include <unordered_map>
using namespace std;

class LRUCache {
public:
  typedef struct DbListNode {
    DbListNode *pre = nullptr;
    DbListNode *next = nullptr;
    int val;
    int key;
  } DblistNode;

  LRUCache(int capacity) { m_cap = capacity; }

  ~LRUCache() {
    auto *p = m_head.next;
    while (p) {
      auto *tmp = p;
      p = p->next;
      delete tmp;
    }
  }

  void RemoveFromList(DbListNode *node) {
    node->pre->next = node->next;
    if (node->next)
      node->next->pre = node->pre;
    if (node == m_tail) {
      m_tail = node->pre;
    }
  }

  void PutFront(DbListNode *node) {
    node->next = m_head.next;
    node->pre = &m_head;
    m_head.next = node;
    if(node->next)
      node->next->pre = node;
    if (node->next == nullptr)
      m_tail = node;
  }

  int get(int key) {
    auto it = map.find(key);
    if (it == map.end())
      return -1;
    auto *node = it->second;
    RemoveFromList(node);
    PutFront(node);
    return node->val;
  }

  void put(int key, int value) {
    auto it = map.find(key);
    if (it != map.end()) {
      auto *node = it->second;
      node->val = value;
      RemoveFromList(node);
      PutFront(node);
    } else {
      if (map.size() == m_cap) {
        // remove
        auto *save = m_tail;
        // this will change m_tail.
        RemoveFromList(m_tail);
        map.erase(save->key);
        delete save;
      }
      auto *node = new DbListNode;
      node->val = value;
      node->key = key;
      map[key] = node;
      PutFront(node);
    }
  }

private:
  DbListNode m_head;
  DbListNode *m_tail = &m_head;
  int m_cap;
  unordered_map<int, DbListNode *> map;
};

int main() {
  LRUCache cache(2);
  cache.put(1, 1);
  cache.put(2, 2);
  cache.get(1);
  cache.put(3, 3);
  cout << cache.get(2) << endl;
  return 0;
}
