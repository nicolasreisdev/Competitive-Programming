// My Solution - get just positive values

class Solution {
public:

    int maxProfit(vector<int>& prices) {
        int ans = 0, lastValue = prices[0];
        for(int i = 0; i < prices.size();i++){
            if(prices[i] - lastValue > 0) ans += prices[i] - lastValue;
            lastValue = prices[i]; 
        }
        return ans;
    }
};