#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minSubArrayLen(int target, vector<int> &nums)
    {
        int l = 0, sum = 0;
        int ans = nums.size() + 1;
        for (int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
            while (sum >= target)
            {
                ans = min(ans, i - l + 1);
                sum -= nums[l];
                l++;
            }
        }
        if (ans == nums.size() + 1)
            return 0;
        return ans;
    }
};