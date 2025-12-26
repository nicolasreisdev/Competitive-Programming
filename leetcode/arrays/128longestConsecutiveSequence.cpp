class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int> ans;
        for(int i = 0; i < nums.size();i++) ans.insert(nums[i]);
        int sizeNums = 0, result = 0;
        int numberBefore = (-1e9 - 10);
        for(auto num: ans){
            if(numberBefore != (-1e9 - 10) and num != numberBefore+1) sizeNums = 0;
            numberBefore = num;
            sizeNums++;
            result = max(sizeNums, result);
        }
        return result;
    }
};