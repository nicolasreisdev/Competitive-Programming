class Solution {
public:
    bool f(vector<int> &piles, double x, int h){
        long long qntd = 0;
        for(int i = 0; i < piles.size();i++){
            qntd += ceil(piles[i]/x);
        }
        if(qntd <= h) return true;
        else return false;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        long long l = 1, r = 1e9;
        while(l <= r){
            int mid = (l+r)/2;
            if(!f(piles, (double)mid, h)) l = mid+1;
            else r = mid-1;
        }

        return l;
    }
};