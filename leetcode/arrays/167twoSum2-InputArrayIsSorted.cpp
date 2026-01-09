class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int idx1 = 0, idx2 = numbers.size()-1;
        while(idx1 < idx2){
            if(numbers[idx1] + numbers[idx2] > target) idx2--;
            else if(numbers[idx1] + numbers[idx2] < target) idx1++;
            else return { idx1+1, idx2+1};
        }
        return {};
    }
};