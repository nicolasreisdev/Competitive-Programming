#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, x, tot; cin >> n;
    vector<int> v, w;
    for(int i = 0; i < n;i++){
        tot = 0;
        cin >> x;
        w.push_back(x);
    }
    for(int i = 0; i < w.size();i++){
        tot = 0;
        for(int j = 0; j < w[i];j++){
            cin >> x;
            tot += x*5;
        }
        tot += w[i]*15;
        v.push_back(tot);
    }
    sort(v.begin(), v.end());
    cout << v[0] << endl;

    return 0;
}