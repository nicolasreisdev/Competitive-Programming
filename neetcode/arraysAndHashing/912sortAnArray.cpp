class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        map<int, int> m;
        for(int i = 0; i < nums.size();i++)m[nums[i]]++;
        vector<int> ans(nums.size());
        int sizeOfArray = 0;
        for(auto [key, value]: m){
            int positions = value;
            while(positions > 0){
                ans[sizeOfArray] = key;
                sizeOfArray++;
                positions--;
            }
        }
    
        return ans;
    }
};