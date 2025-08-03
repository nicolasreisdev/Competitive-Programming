#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void moveZeroes(vector<int> &nums)
    {
        int posZero = 0, posElem = 0;
        if (nums.size() == 1)
            return;
        while (posElem != nums.size())
        {
            if (nums[posElem] != 0)
            {
                swap(nums[posZero], nums[posElem]);
                posZero++;
            }
            posElem++;
        }
    }
};