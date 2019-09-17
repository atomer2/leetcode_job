class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> table(m, 1);
        for(int i=1; i<n; ++i){
            for(int j = 1; j < m; ++j){
                  table[j] = table[j-1] + table[j];             
            }          
        }
        return table.back();
    }
};
