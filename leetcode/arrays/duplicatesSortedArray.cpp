#include <bits/stdc++.h>
using namespace std;

class Solution{

    int removeDuplicates(vector<int> nums){
        int aux = nums[0], pos = 1;
        // {1, 1, 2, 2, 3, 4}
        for (int i = 1; i < nums.size(); i++){
            if (nums[i] != aux)
            {
                nums[pos++] = nums[i];
                aux = nums[i];
            }
        }
        return pos;
    }
};