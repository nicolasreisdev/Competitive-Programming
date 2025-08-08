#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int ans = -1e6, lastSum = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (lastSum < 0)
                lastSum = 0;
            lastSum += nums[i];
            ans = max(ans, lastSum);
        }
        return ans;
    }
};