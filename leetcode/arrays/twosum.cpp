#include <bits/stdc++.h>
using namespace std;


// Naive solution

class Solution{
public:
    vector<int> twoSum(vector<int> &nums, int target){
        vector<int> result(2);
        for (int i = 0; i < nums.size(); i++){
            int sum = 0;
            sum += nums[i];
            for (int j = i + 1; j < nums.size(); j++){
                if (sum + nums[j] == target){
                    result[0] = i;
                    result[1] = j;
                    break;
                }
            }
        }
        return result;
    }
};

// best solution

class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target){
        vector<int> result(2);
        map<int, int> m;
        for (int i = 0; i < nums.size(); i++){
            int x = target - nums[i];
            if(m.find(x) != m.end()){
                vector<int> result(2);
                result[0] = i;
                result[1] = m.at(x);
                return result;
            }
            m.insert({nums[i], i});
        }
        return result;
    }
};