#include <bits/stdc++.h>

using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0);
#define endl '\n'

typedef long long ll;

int main(){

    int n; cin >> n;
    vector<int> v;
    for(int i = 0; i < n;i++){
        int x; cin >> x; v.push_back(x);
    }
    ll ans = 0, count = 0;
    for(int i = 1; i < n;i++){
        if(v[i] > v[i-1]){
            count++;
            ans = max(count, ans);  
        }
        else{
            count = 0;
        }
    }
    cout << ans+1 << endl;

    return 0;
}