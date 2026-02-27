// My Solution
class Solution {
private:
    bool validateFunc(vector<int>& weights, int &d, int &x){
        int cont = 0, bucket = 1;
        for(int i = 0; i < weights.size();i++){
            if(cont+weights[i] <= x) cont+=weights[i];
            else{
                cont = weights[i];
                bucket++;
            }
        }
        return bucket <= d;
    }
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int l = 0, r = 0;
        for(int i = 0; i < weights.size();i++){
            r+=weights[i];
            l = max(l, weights[i]);
        }
        while(l <= r){
            int mid = (l + r) / 2;
            if(validateFunc(weights, days, mid))r = mid-1;
            else l = mid+1;
        }
        return l;
    }
};