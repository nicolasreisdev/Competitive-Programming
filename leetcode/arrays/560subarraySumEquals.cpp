class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int currSum = 0, ans = 0;
        map<int, int> prefixSum;
        prefixSum[0] = 1;
        for(int number: nums){
            currSum += number;
            int diff = currSum - k;
            ans += prefixSum[diff];
            prefixSum[currSum]++;
        }
        return ans;
    }
};