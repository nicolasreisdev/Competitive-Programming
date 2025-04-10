#include <bits/stdc++.h>
using namespace std;


#define fastio ios_base::sync_with_stdio(0); cin.tie(0);
#define end '\n'

typedef long long ll;


int main(){

    int k, n, w; cin >> k >> n >> w;
    ll ans = 0;
    for(int i = 1; i <= w;i++){
        if(k*i <= n){
            n -= k*i;
        }
        else{
            ans += k*i;
        }
    }
    if(ans > 0)
        cout << ans-n << endl;
    else cout << 0 << endl;

    return 0;
}