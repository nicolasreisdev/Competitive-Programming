#include <bits/stdc++.h>
using namespace std;

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
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
const ll mod = 998244353;

int main(){
    fastio;
    int n, q;
    cin >> n >> q;
    vector<vector<ll>> g(n + 1);
    ll Xk = 0;
    for (int i = 0; i < q; i++){
        int query, u, v;
        cin >> query >> u >> v;
        query = 1 + ((query * (1 + Xk) % mod) % 2);
        u = 1 + ((u * (1 + Xk) % mod) % n);
        v = 1 + ((v * (1 + Xk) % mod) % n);
        if (query == 1){
            g[u].pb(v);
            g[v].pb(u);
        }
        else{
            
        }
    }

    return 0;
}