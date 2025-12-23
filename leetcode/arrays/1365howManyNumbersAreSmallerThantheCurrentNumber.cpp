#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> aux = nums;
        sort(aux.begin(), aux.end());
        map<int, int> m;
        for(int i = 0; i < aux.size();i++){
            if(m.find(aux[i]) != m.end()) continue;
            else m[aux[i]] = i;
        }
        vector<int> ans;
        for(int i = 0; i < nums.size();i++){
            ans.push_back(m[nums[i]]);
        }
        return ans;
    }
};