#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> elems;
        for(int i = 0; i < nums.size();i++) elems[nums[i]]++;
        vector<int> ans;
        vector<pair<int, int>> aux(elems.begin(), elems.end());
        sort(aux.begin(), aux.end(), [](pair<int, int> &a, pair<int, int> &b){
            return a.second > b.second;
        });
        for(auto [key, value]: aux){
            if(ans.size() < k) ans.push_back(key);
        }
        return ans;
    }
};