// one pass
/*
* The meaning of left, i, and right：
*
* 000000111111XXXXXX222222
*       ^     ^    ^
*      left   i  right
**/
class Solution {
    public:
    void sortColors(vector<int>& nums) {
        size_t cnt = nums.size();
        int i = 0;
        int left = 0;
        int right = cnt - 1;
        while(i <= right){
            while(nums[i] == 2 && i <= right){
                swap(nums[i], nums[right]);
                right--;         
            }
            if(nums[i] == 0){
                swap(nums[i], nums[left]);
                left++;
                i++;
            }
            while(i <= right && nums[i] == 1)
                i++;
        }
    }
};
