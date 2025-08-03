#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int, int> m;
        for(int i = 0; i < nums.size();i++){
            if(m.find(nums[i]) != m.end()){
                m[nums[i]] = m[nums[i]]+1;
            }
            else{
                m[nums[i]] = 1;
            }
        }
        int ans = 0;
        for(auto &[elem, appears]: m){
            if(appears > nums.size()/2)
                ans = elem;
        }
        return ans;
    }
};