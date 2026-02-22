class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int> correctHeights(heights.begin(), heights.end());
        sort(correctHeights.begin(), correctHeights.end());
        int ans = 0;
        for(int i = 0; i < correctHeights.size();i++){
            if(correctHeights[i] != heights[i])ans++;
        }
        return ans;
    }
};