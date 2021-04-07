class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        auto k = min(nums1.size(), nums2.size());
        vector<int>& arrs = k==nums1.size()?nums1:nums2;
        vector<int>& arrl = k==nums1.size()?nums2:nums1;
        int m = arrs.size();
        int n = arrl.size();
        int l = 0, r = m;
        int half = (m+n+1)>>1;
        while(l<=r){
            int i = l + ((r-l) >> 1);
            int j = half - i;
            if(i>0 && arrs[i-1] > arrl[j]){
                r = i-1;
            }else if(i<m && arrl[j-1] > arrs[i]){
                l = i+1;
            }else{
                // i is perfect.
                int maxLeft;
                if(i==0) maxLeft = arrl[j-1];
                else if(j==0) maxLeft = arrs[i-1];
                else maxLeft = max(arrs[i-1], arrl[j-1]);
                
                if((m+n)&1) return maxLeft;
                
                int minRight;
                if(i==m) minRight = arrl[j];
                else if(j==n) minRight = arrs[i];
                else minRight = min(arrs[i], arrl[j]);
                
                return (maxLeft+minRight)/2.0;
            }
        }
        return 0.0;
    }
};
