#pragma once
#include <bits/stdc++.h>
#include <boost/algorithm/string.hpp>

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};


using namespace boost::algorithm;

// [nums1, num2, nums3]
std::vector<int> parseIntVector(char* s){
  std::vector<int> ret;

  std::string str(s);
  trim(str);
  
  if(str.empty())
    return ret;

  const char* ps = str.c_str();
  while(*ps){
    if(*ps == ',' || *ps == '[' || *ps ==']')
      ps++;
    else{
      int i = atoi(ps);
      ret.push_back(i);
      while(*ps && *ps != ',') ps++;
    }
  }

  return ret;
}

std::ostream& operator<<(std::ostream& os, const std::vector<int>& vi){
  std::copy(vi.begin(), vi.end(), std::ostream_iterator<int>(os, " "));
  return os;
}


