#include <bits/stdc++.h>
using namespace std;

// Naive solution

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int minPrice = INT_MAX;
        int maxProfit = 0;

        for (int price : prices)
        {
            if (price < minPrice)
            {
                minPrice = price;
            }
            else if (price - minPrice > maxProfit)
            {
                maxProfit = price - minPrice;
            }
        }
        return maxProfit;
    }
};


// My solution

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int init = 0, end = 1;
        int ans = 0;
        for (; end < prices.size(); end++)
        {
            if (prices[init] < prices[end])
            {
                ans = max(ans, prices[end] - prices[init]);
            }
            else
                init = end;
        }
        return ans;
    }
};
