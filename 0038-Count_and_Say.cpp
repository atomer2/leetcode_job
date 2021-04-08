#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

#include "utils.h"

using namespace std;

class Solution {
public:
  string countAndSay(int n){
    if(n==1)
      return "1";
    string rs = "1";
    for(int i=2; i<=n; i++){
      int j = 0;
      string str;
      while(j < rs.size()) {
        char digit = rs[j];
        int count = 1;
        j++; 
        while(j<rs.size() && digit == rs[j]){
          j++;
          count++;
        }
        str += to_string(count) + digit;
      }
      swap(rs, str);
    }
    return rs;
  }
};

int main() { 
  return 0; 
}
