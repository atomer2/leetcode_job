// follow up question of 84. Largest Rectangle in Histogram
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.empty())
            return 0;

        int h = matrix.size();
        int w = matrix[0].size();
        vector<int> height(w, 0);
        int res = 0;
        for(int i=0; i<h; ++i){
            vector<int> lastLeft(w, -1);
            vector<int> lastRight(w, w);
            for(int j=0; j<w; ++j){  
                if(matrix[i][j] == '1')
                    height[j]++;
                else
                    height[j]=0;
            }
            // find last left
            for(int j=1; j<w; ++j){
                int p = j-1;
                while(p >= 0 && height[p] >= height[j])
                    p = lastLeft[p];
                lastLeft[j] = p;                
            }
            // find last right
            for(int j=w-2; j>=0; --j){
                int p = j+1;
                while(p < w && height[p] >= height[j])
                    p = lastRight[p];
                lastRight[j] = p;                
            }
            for(int j=0; j<w; ++j){
                int area = (lastRight[j]-lastLeft[j]-1)*height[j];
                if(area > res)
                    res = area;
            }
        }
        return res;
    }
};
