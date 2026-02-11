class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans(nums1.size());
        map<int,int> idx; // f = number, s = index
        for(int i = 0; i < nums2.size();i++)idx[nums2[i]] = i;
        for(int i = 0; i < nums1.size();i++){
            int j = idx[nums1[i]];
            while(j < nums2.size() and nums2[j] <= nums1[i]){
                j++;
            }
            if(j == nums2.size()) ans[i] = -1;
            else ans[i] = nums2[j];
        }
        return ans;
    }
};