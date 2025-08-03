#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        map<int, int> m; // first = elem, second = index
        for(int i = 0; i < nums.size();i++){
            if(m.find(nums[i]) != m.end()){
                int idx1 = m[nums[i]];
                int idx2 = i;
                if(abs(idx2 - idx1) <= k) return true;
                m[nums[i]] = i;
            }
            else{
                m[nums[i]] = i;
            }
        }
        return false;
    }
};