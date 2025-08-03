#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> intersection(vector<int> &nums1, vector<int> &nums2)
    {
        set<int> s, help;
        for (int i = 0; i < nums1.size(); i++)
        {
            s.insert(nums1[i]);
        }
        for (int i = 0; i < nums2.size(); i++)
        {
            if (s.find(nums2[i]) != s.end())
            {
                help.insert(nums2[i]);
            }
        }
        vector<int> ans;
        for (auto &elem : help)
            ans.push_back(elem);
        return ans;
    }
};