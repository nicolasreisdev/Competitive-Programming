#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int aux = nums[0];
        for(int i = 1; i < nums.size();i++) if(nums[i] != aux+1){
            return aux+1;
        }else aux++;
        if(nums[0] != 0) return 0;
        return aux+1;
    }
};