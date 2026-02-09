class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        vector<int> ans(arr.size());
        int greater = -1;
        for(int i = arr.size()-1; i >= 0;i--){
            if(i == arr.size()-1){
                ans[i] = greater;
                continue;
            }
            ans[i] = max(greater, arr[i+1]);
            greater = ans[i];
        }
        return ans;
    }
};