#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int longestMountain(vector<int> &arr)
    {
        int ans = 0;
        for (int i = 1; i < arr.size() - 1; i++)
        {
            if (arr[i] > arr[i - 1] && arr[i] > arr[i + 1])
            {
                int l = i, r = i;
                while (l > 0 and arr[l] > arr[l - 1])
                    l--;
                while (r < arr.size() - 1 and arr[r] > arr[r + 1])
                    r++;
                ans = max(ans, r - l + 1);
            }
        }
        return ans;
    }
};