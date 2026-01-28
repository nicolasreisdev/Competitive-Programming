// My Solution

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        set<int> aux;
        for(int i = 0; i < nums.size();i++){
            if(aux.find(nums[i]) != aux.end()) return nums[i];
            aux.insert(nums[i]);
        }
        return -1;
    }
};

// Best Solution

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        for (int num : nums) {
            int idx = abs(num) - 1;
            if (nums[idx] < 0) {
                return abs(num);
            }
            nums[idx] *= -1;
        }
        return -1;
    }
};