class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        vector<int> ans = nums;
        ans.resize(2*nums.size());
        for(int i = nums.size(); i < nums.size()*2;i++) ans[i] = nums[i-nums.size()];
        return ans;
    }
};