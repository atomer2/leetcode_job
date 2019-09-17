// backtrace
class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> result;
        vector<int> temp;
        combineBacktrace(result, temp, n, 1, k);
        return result;

    }

    void combineBacktrace(vector<vector<int>>& res, vector<int> &vec, int n, int left, int count){
        if(count == 0){
            res.push_back(vec);
            return;            
        }

        for(int i = left; i<= n - count + 1; i++){
            vec.push_back(i);
            combineBacktrace(res, vec, n, i+1, count - 1);
            vec.pop_back();
        }
    }
};
