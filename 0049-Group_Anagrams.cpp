#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

#include "utils.h"

using namespace std;

class Solution {
public:
  vector<vector<string>> groupAnagrams(vector<string>& strs){
    unordered_map<string, vector<string>> sm;
    for(auto&& str: strs){
      string keystr = str;
      sort(keystr.begin(), keystr.end());
      sm[keystr].push_back(str);
    }
    vector<vector<string>> ret;
    for(auto&& p: sm){
      ret.push_back(std::move(p.second));
    }
    return ret;
  }
};

int main() { 
  return 0; 
}
