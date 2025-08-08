#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int numOfUnplacedFruits(vector<int> &fruits, vector<int> &baskets)
    {
        int ans = fruits.size();
        for (int i = 0; i < fruits.size(); i++)
        {
            int j = 0;
            while (j < baskets.size() && baskets[j] < fruits[i])
            {
                j++;
            }
            if (j < baskets.size() && baskets[j] >= fruits[i])
                baskets.erase(baskets.begin() + j);
        }
        return baskets.size();
    }
};