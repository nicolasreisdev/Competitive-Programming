#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool validNumber(vector<int> &nums, int startValue)
    {
        int sum = startValue;
        for (int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
            if (sum < 1)
                return false;
        }
        return true;
    }

    int minStartValue(vector<int> &nums)
    {
        int l = 1, r = 1e5;
        while (l < r)
        {
            int mid = (l + r) / 2;
            if (validNumber(nums, mid))
            {
                r = mid;
            }
            else
            {
                l = mid + 1;
            }
        }
        return l;
    }
};