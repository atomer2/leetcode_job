// My solution, terrible
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.empty() || matrix[0].empty())
            return false;
        int row = findRow(matrix, target, 0, matrix.size()-1);
        if(row == -1)
            return false;
        auto idx = lower_bound(matrix[row].begin(), matrix[row].end(), target);
        if(idx != matrix[row].end()){
            if(*idx == target)
                return true;
        }
        return false;
    }

    int findRow(vector<vector<int>>& matrix, int target, int p, int q){
        if(p > q)
            return -1;
        int mid = (p+q)/2;
        if(matrix[mid].front() <= target && matrix[mid].back() >= target)
            return mid;
        if(matrix[mid].front() > target)
            return findRow(matrix, target, p, mid-1);
        if(matrix[mid].back() < target)
            return findRow(matrix, target, mid+1, q);
        return -1;
    }
};
