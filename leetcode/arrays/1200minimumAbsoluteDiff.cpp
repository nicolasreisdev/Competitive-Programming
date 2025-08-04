#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> minimumAbsDifference(vector<int> &arr)
    {
        sort(arr.begin(), arr.end());
        int minDif = 1e7;
        for (int i = 1; i < arr.size(); i++)
        {
            if (abs(arr[i] - arr[i - 1]) < minDif)
            {
                minDif = abs(arr[i] - arr[i - 1]);
            }
        }
        vector<vector<int>> ans;
        for (int i = 1; i < arr.size(); i++)
        {
            if (abs(arr[i] - arr[i - 1]) == minDif)
            {
                vector<int> aux;
                aux.push_back(arr[i - 1]);
                aux.push_back(arr[i]);
                ans.push_back(aux);
            }
        }
        return ans;
    }
};