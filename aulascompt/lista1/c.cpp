#include <bits/stdc++.h>
using namespace std;

int main(){
    int n; cin >> n;
    while (n != 0){
        double x, r1 = 0, r2 = 0;
        double tot = 0, d;
        vector<double> v;
        for(int i = 0; i < n;i++){
            cin >> x;
            tot += x;
            v.push_back(x);
        }
        tot /= n;
        for(int i = 0; i < n;i++){
            d = (double)(long)((v[i] - tot)*100.0)/100.0;
            if(d > 0) r1+= d;
            else r2 += d;
        }
        if(r2 < 0) r2 *= -1;
        if(r1 > r2) cout << fixed << setprecision(2) << "$" <<  r1 << "\n";
        else cout << fixed << setprecision(2) << "$" << r2 << "\n";

        cin >> n;
    }

    return 0;
}