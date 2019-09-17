// DP
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        if(grid.empty() || grid[0].empty())
            return 0;
        int m = grid[0].size();  // column
        int n = grid.size();     // row
        vector<int> table(m, 0);
        int acc = 0;
        for(int i=0; i< m; ++i) {
            acc += grid[0][i];
            table[i] = acc;
        }
        for(int i=1; i<n; i++){
            table[0] = table[0] + grid[i][0];
            for(int j=1; j<m; ++j){
                table[j] = min(table[j-1], table[j]) + grid[i][j];
            }
        }
        return table.back();
    }
};
