#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int n; cin >> n;
    map<ll, ll> m;
    for(int i = 0; i < n;i++){
        ll x;
        cin >> x;
        m[x]++;
    }

    ll ans = 0;
    for(auto [x, count]: m){
        if(count >= 2){
            ans += count/2;
        }
    }

    cout << ans/2 << endl;


    return 0;
}