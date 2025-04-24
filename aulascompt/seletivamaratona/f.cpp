#include <bits/stdc++.h>
using namespace std;


#define fastio ios_base::sync_with_stdio(0); cin.tie(0);
#define endl '\n'
#define all(x) x.begin(),  x.end()

typedef long long ll;


int main(){
    fastio;
    int n; cin >> n;
    map<ll, ll> m;
    for(int i = 0; i < n;i++){
        ll x; cin >> x; m[x-i] += x;
    }
    vector<pair<ll, ll>> v(all(m));
    sort(all(v), [](pair<ll, ll> &a, pair<ll, ll> &b){
        return a.second > b.second;
    });

    cout << v[0].second << endl;

    return 0;
}