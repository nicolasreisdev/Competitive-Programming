#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define endl '\n'
#define pb push_back
#define rm pop_back
#define f first
#define s second
#define sz size
#define in insert

typedef pair<int, int> p;
typedef long long ll;
const int MAX = 0x3f3f3f3f;
const ll LMAX = 0x3f3f3f3f3f3f3f3f;

int main(){
    fastio;

    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        set<ll> a, b;
        for(int i = 0; i < n;i++){
            ll x; cin >> x;
            a.insert(x);
        }
        ll ans = a.size()-1;
        for(int i = 0; i < n;i++){
            ll x; cin >> x;
            b.insert(x);
        }
        ans += b.size()-1;
        if(ans >= 2) cout << "YES" << endl;
        else cout << "NO" << endl;
        
    }

    return 0;
}