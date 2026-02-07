class Solution {
public:
    long long findTheArrayConcVal(vector<int>& nums) {
        int l = 0, r = nums.size()-1;
        long long ans = 0;
        while(l < r){
            string valueOne = to_string(nums[l]);
            string valueTwo = to_string(nums[r]);
            string res = valueOne + valueTwo;
            ans += stoi(res);
            l++;
            r--;
        }
        if(l == r)ans += nums[l];
        return ans;
    }
};