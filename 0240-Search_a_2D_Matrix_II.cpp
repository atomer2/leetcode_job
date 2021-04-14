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
  bool searchMatrix(vector<vector<int>> &matrix, int target){
    int rows = matrix.size();
    if(rows==0)
      return false;
    int cols =  matrix[0].size();
    int m = 0, n = cols-1;
    while(m<rows && n>=0){
      if(target > matrix[m][n]) m++;
      else if(target < matrix[m][n]) n--;
      else
        return true;
    }
    return false;
  }
};

int main() { 
  return 0; 
}
