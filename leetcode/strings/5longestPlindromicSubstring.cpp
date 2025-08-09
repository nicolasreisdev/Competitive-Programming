#include <bits/stdc++.h>
using namespace std;


// Initial solution

class Solution
{
public:
    string longestPalindrome(string s)
    {

        string ans;
        int caract = 1;
        for (int i = 0; i < s.size(); i++)
        {
            for (int j = 1; j <= s.size() - i; j++)
            {
                string sub = s.substr(i, j);
                if (isPalindrome(sub) and j > caract)
                {
                    ans = sub;
                    caract = sub.size();
                }
            }
        }
        if (caract > 1)
            return ans;
        return s.substr(0, 1);
    }

    bool isPalindrome(string s)
    {
        string aux = s;
        reverse(aux.begin(), aux.end());
        return s == aux;
    }
};


// AC

class Solution
{
public:
    string longestPalindrome(string s)
    {
        if (s.empty())
            return "";

        int start = 0, end = 0, maxTam = 0;
        for (int i = 0; i < s.size(); i++)
        {
            int len1 = expandFromMiddle(s, i, i);
            int len2 = expandFromMiddle(s, i, i + 1);
            int len = max(len1, len2);
            if (len > (end - start))
            {
                start = i - (len - 1) / 2;
                end = i + len / 2;
            }
        }
        return s.substr(start, end - start + 1);
    }

    int expandFromMiddle(string s, int l, int r)
    {
        if (s.empty() || l > r)
            return 0;
        while (l >= 0 && r < s.size() && s[l] == s[r])
        {
            r++;
            l--;
        }
        return r - l - 1;
    }
};