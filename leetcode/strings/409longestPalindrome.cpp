#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int longestPalindrome(string s)
    {
        map<char, int> m;
        for (int i = 0; i < s.size(); i++)
        {
            m[s[i]]++;
        }
        int ans = 0;
        bool unique = false;
        for (auto &[letter, x] : m)
        {
            if (x % 2 == 0)
                ans += x;
            else
            {
                ans += x - 1;
                unique = true;
            }
        }
        if (unique)
            return ans + 1;
        return ans;
    }
};