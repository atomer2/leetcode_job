// beautiful solution here
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        if(matrix.empty())
            return;
        int cw[2] = {1, 1};
        int h = matrix.size();
        int w = matrix[0].size();
        for(int i=0; i<h; i++){
            if(matrix[i][0] == 0){
                cw[0] = 0;
                break;
            }
        }
        for(int i=0; i<w; i++){
            if(matrix[0][i] == 0){
                cw[1] = 0;
                break;
            }
        }
        for(int i=1; i<h; i++){
            for(int j=1; j<w; j++){
                if(matrix[i][j] == 0){
                    matrix[0][j] = 0;
                    matrix[i][0] = 0;
                }
            }
        }
        for(int i=1; i<h; i++){
            if(matrix[i][0] == 0){
                for(int j=1; j<w; j++){
                    matrix[i][j] = 0;
                }
            }
        }
        for(int i=1; i<w; i++){
            if(matrix[0][i] == 0){
                for(int j=1; j<h; j++){
                    matrix[j][i] = 0;
                }
            }
        }
        if(cw[0] == 0){
            for(int i=0;i<h;i++){
                matrix[i][0] = 0;
            }
        }
        if(cw[1] == 0){
            for(int i=0; i<w; i++){
                matrix[0][i] = 0;
            }
        }
    }
};
