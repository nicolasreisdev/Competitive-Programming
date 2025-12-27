    class Solution {
    public:
        vector<int> majorityElement(vector<int>& nums) {
            map<int, int> m;
            for(int i = 0; i < nums.size();i++)m[nums[i]]++;
            vector<int> ans;
            for(auto [key, value]: m){
                if(value > floor(nums.size()/3)) ans.push_back(key);
            }
            return ans;
        }
    };