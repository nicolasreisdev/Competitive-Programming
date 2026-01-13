class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0, r = nums.size()-1;
        int ans = nums[l];
        while(l <= r){
            if(nums[l] < nums[r] and nums[l] < ans){
                ans = nums[l];
                break;
            }
            int mid = (l + r)/2;
            ans = min(ans, nums[mid]);
            if(nums[mid] >= nums[l]) l = mid+1;
            else r = mid-1;
        }
        return ans;
    }
};