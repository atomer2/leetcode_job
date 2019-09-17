class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> temp;
        for(int i=0; i<nums.size()+1; i++){
            subsets_n(result, temp, nums, nums.size(), i, 0);
        }
        return result;
    }

    // backtrace
    void subsets_n(vector<vector<int>> &result, vector<int>& temp, vector<int>&nums, int n, int count, int begin){
        if(count == 0){
            result.push_back(temp);
            return;           
        }

        for(int i=begin; i< n-count+1; i++){
            temp.push_back(nums[i]);
            subsets_n(result, temp, nums, n, count-1, i+1);
            temp.pop_back();
        }     
    }
};
