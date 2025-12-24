#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
       map<string, vector<string>> mapOfGroups;
       for(auto &s: strs){
            string sortedS = s;
            sort(sortedS.begin(), sortedS.end());
            mapOfGroups[sortedS].push_back(s);
       }
       vector<vector<string>> ans;
       for(auto [key, value]: mapOfGroups){
            ans.push_back(value);
       } 
       return ans; 
    }
};