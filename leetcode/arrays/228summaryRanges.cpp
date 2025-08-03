#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<string> summaryRanges(vector<int> &nums)
    {
        vector<string> ans;
        if (nums.empty())
            return ans;
        int pos = 0, startRange = nums[0];
        ans.push_back(to_string(startRange));
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] == (nums[i - 1] + 1))
            {
                ans[pos] = to_string(startRange) + "->" + to_string(nums[i]);
            }
            else
            {
                startRange = nums[i];
                ans.push_back(to_string(nums[i]));
                pos++;
            }
        }
        return ans;
    }
};