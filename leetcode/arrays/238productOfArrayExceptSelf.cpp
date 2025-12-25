#include <bits/stdc++.h>
using namespace std;

// Division solution

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int sum = 1, zeroCount = 0;
        bool flag = false;
        vector<int> ans(nums.size());
        for(int i = 0; i < nums.size();i++){
            if(nums[i] == 0) zeroCount++;
            else sum *= nums[i];
        }
        if(zeroCount > 1) return ans;

        for(int i = 0; i < nums.size();i++){
            if(zeroCount) ans[i] = nums[i] == 0 ? sum : 0;
            else ans[i] = sum/nums[i];
        }
        return ans;
    }
};


// Prefix and Suffix solution


class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n);
        vector<int> pref(n);
        vector<int> suff(n);

        pref[0] = 1;
        suff[n - 1] = 1;
        for (int i = 1; i < n; i++) {
            pref[i] = nums[i - 1] * pref[i - 1];
        }
        for (int i = n - 2; i >= 0; i--) {
            suff[i] = nums[i + 1] * suff[i + 1];
        }
        for (int i = 0; i < n; i++) {
            res[i] = pref[i] * suff[i];
        }
        return res;
    }
};


// Prefix and Suffix optimal solution

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n, 1);

        for (int i = 1; i < n; i++) {
            res[i] = res[i - 1] * nums[i - 1];
        }

        int postfix = 1;
        for (int i = n - 1; i >= 0; i--) {
            res[i] *= postfix;
            postfix *= nums[i];
        }
        return res;
    }
};