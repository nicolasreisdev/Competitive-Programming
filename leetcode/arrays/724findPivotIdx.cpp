#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int pivotIndex(vector<int> &nums)
    {
        vector<int> prefixSum;
        prefixSum.resize(nums.size());
        int sum = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
            prefixSum[i] = sum;
        }
        for (int i = 0; i < nums.size(); i++)
        {
            if ((prefixSum[i] - nums[i]) == (prefixSum[nums.size() - 1] - prefixSum[i]))
            {
                return i;
            }
        }
        return -1;
    }
};