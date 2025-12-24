#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) return false;
        map<char, int> stringOne;
        map<char, int> stringTwo;
        for(int i = 0; i < s.size();i++){
            stringOne[s[i]] += 1;
            stringTwo[t[i]] += 1;
        }
        for(auto [key, value]: stringOne){
            if(stringTwo[key] != value) return false;
        }
        return true;
    }
};