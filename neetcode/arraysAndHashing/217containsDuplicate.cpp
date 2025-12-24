#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool containsDuplicate(vector<int> &nums)
    {
        set<int> s;
        bool ans = false;
        for (int i = 0; i < nums.size(); i++)
        {
            if (s.find(nums[i]) != s.end())
            {
                ans = true;
                break;
            }
            s.insert(nums[i]);
        }
        return ans;
    }
};