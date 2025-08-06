#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int strStr(string haystack, string needle)
    {
        int needSize = needle.size();
        for (int i = 0; i < haystack.size(); i++)
        {
            if (haystack.substr(i, needSize) == needle)
                return i;
        }
        return -1;
    }
};