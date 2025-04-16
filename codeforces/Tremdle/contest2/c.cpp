#include <bits/stdc++.h>

using namespace std;

#define fastio ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

int main(){

    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<int> v;
        for(int i = 0; i < n;i++){
            int x; cin >> x; v.push_back(x);
        }
        reverse(v.begin(), v.end());
        ll ans = 0;
        for(auto &e: v){
            if(e > 1) ans = 1;
            else ans ^= 1;
        }
        if(ans) cout << "First" << endl;
        else cout << "Second" << endl;
    }

    return 0;
}