#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int thirdMax(vector<int> &nums)
    {
        set<int> s;
        for (int i = 0; i < nums.size(); i++)
        {
            s.insert(nums[i]);
        }
        int ans = 0;
        if (s.size() < 3)
        {
            ans = *s.rbegin();
        }
        else
        {
            auto it = s.rbegin();
            it++;
            it++;
            ans = *it;
        }
        return ans;
    }
};