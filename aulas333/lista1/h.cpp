#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, k, r; cin >> n;
    while(n!=0){
        r = 0;
        vector<int> x;
        for(int i = 0; i < n;i++){
            cin >> k;
            x.push_back(k);
        }
        for(int i = 0; i < x.size();i++){
            if (x[i] < x[(i + 1) % n]){
                if (x[(i + 1) % n] > x[(i + 2) % n])r++;
            }

            if (x[i] > x[(i + 1) % n]){
                if (x[(i + 1) % n] < x[(i + 2) % n])r++;
            }
        }
        cout << r << endl;
        cin >> n;
    }



    return 0;
}