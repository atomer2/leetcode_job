#include <algorithm>
#include <iostream>
#include <limits.h>
#include <memory>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>

#include "utils.h"

using namespace std;

class Trie {
private:
  struct TrieNode {
    std::unique_ptr<TrieNode> nodes_[26];
    bool endMark_ = false;
  };

  TrieNode root_;

public:
  /** Initialize your data structure here. */
  Trie() {}

  /** Inserts a word into the trie. */
  void insert(string word) {
    TrieNode* curr = &root_;
    for(int i=0; i<word.size(); i++){
      TrieNode* below = curr->nodes_[word[i]-'a'].get();
      if(!below){
        below = new TrieNode;
        curr->nodes_[word[i]-'a'].reset(below);
      }
      curr = below;
    }
    curr->endMark_ = true;
  }

  /** Returns if the word is in the trie. */
  bool search(string word) {
    TrieNode *curr = &root_;
    for(int i=0; i<word.size(); i++){
      TrieNode* below = curr->nodes_[word[i]-'a'].get();
      if(!below)
        return false;
      curr = below;
    }
    return curr->endMark_;
  }

  /** Returns if there is any word in the trie that starts with the given
   * prefix. */
  bool startsWith(string prefix) {
    TrieNode *curr = &root_;
    for(int i=0; i<prefix.size(); i++){
      TrieNode* below = curr->nodes_[prefix[i]-'a'].get();
      if(!below)
        return false;
      curr = below;
    }
    return true;
  }

};

int main() { return 0; }
