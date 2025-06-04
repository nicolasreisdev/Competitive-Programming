#include <bits/stdc++.h>
using namespace std;


typedef long long ll;

// const ll p = 1e9+7;

int main()
{
    int n; cin >> n;
    vector<int> v(n);
    ll sum = 0;
    for(int i = 0; i < n;i++){
        int x; cin >> x;v[i] = x;
        sum += x;
    }
    ll ans = 0;
    for(int i = 0; i < n;i++){
        sum -= v[i];
        ans += v[i]*sum;
    }
    cout << ans << endl;
    

    return 0;
}