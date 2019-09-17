class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int left = 0;
        int currCnt = 0;
        int currVal = nums.empty()?0:nums[0];
        for(int i=0; i<nums.size(); ++i){
            if(currVal == nums[i]){
                if(currCnt < 2){
                    swap(nums[left], nums[i]);
                    currCnt++;
                    left++;
                }
            }else{
                currVal = nums[i];
                currCnt = 1;
                swap(nums[left], nums[i]);
                left++;
            }      
        }   
        return left;
    }
};
