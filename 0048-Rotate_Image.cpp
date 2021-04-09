#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

#include "utils.h"

using namespace std;

class Solution {
public:
  void rotate(vector<vector<int>>& matrix){
    // Just use two pass.
    if(matrix.empty())
      return;
    int rows = matrix.size();
    int cols = matrix[0].size();

    for(int i=0; i<rows; i++){
      for(int j=i+1; j<cols; j++){
        swap(matrix[i][j], matrix[j][i]);
      }
    }
    
    for(int i=0; i<rows; i++){
      for(int j=0; j<cols/2; j++){
        swap(matrix[i][j], matrix[i][cols-1-j]);
      }
    }
  }
};

int main() { 
  return 0; 
}
