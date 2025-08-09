#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        int l = 0, ans = 0;
        set<char> mySet;
        for (int i = 0; i < s.size(); i++)
        {
            while (mySet.find(s[i]) != mySet.end())
            {
                mySet.erase(s[l]);
                l++;
            }
            mySet.insert(s[i]);
            ans = max(ans, i - l + 1);
        }
        return ans;
    }
};