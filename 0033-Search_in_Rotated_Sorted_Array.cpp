// My solution
class Solution {
public:
    int search(vector<int>& nums, int target) {
        return searchImpl(nums, target, 0, nums.size()-1);
    }

    int searchImpl(vector<int> &nums, int target, int p, int q){
        if(q < p)
            return -1;
        int mid = (p + q) / 2;
        if(nums[mid] == target)
            return mid;
        if(target > nums[mid]){
            if(nums[q] < nums[mid] || nums[q] >= target){
                return searchImpl(nums, target, mid+1, q);
            }else if(nums[p] > nums[mid]){
                return searchImpl(nums, target, p, mid-1);
            }
        }
        if(target < nums[mid]){
            if(nums[p] > nums[mid] || nums[p] <= target){
                return searchImpl(nums, target, p, mid-1);
            }else if(nums[q] < nums[mid]){
                return searchImpl(nums, target, mid+1, q);
            }
        }
        return -1;
    }
};
