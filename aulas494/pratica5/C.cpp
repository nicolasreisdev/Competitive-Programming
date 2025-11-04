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

int find(int x, vector<ll> &parent){
    if(parent[x] != x) parent[x] = find(parent[x], parent);
    return parent[x];
}

void dfs(int u, int parent, vector<ll> &fa, vector<vector<ll>> &g){
    fa[u] = parent;
    for(ll &v: g[u]){
        if(v == parent) continue;
        
        dfs(v, u, fa, g);
    }
}

void mergeVert(int x, int y, vector<ll> &parent, vector<ll> &siz, vector<ll> &fa,  vector<vector<ll>> &g){
    int px = find(x, parent), py = find(y, parent);
    if(siz[px] > siz[py]) swap(px, py), swap(x, y);
    
    dfs(x, y, fa, g);

    g[x].pb(y), g[y].pb(x);

    siz[py] += siz[px], parent[px] = py;
}

int main(){
    fastio;

    int n, q; cin >> n >> q;
    vector<vector<ll>> g(n + 1);
    vector<ll> parent(n+1);
    vector<ll> siz(n+1);
    vector<ll> fa(n+1);
    ll Xk = 0;

    for (int i = 1; i <= n; i++){
        parent[i] = i; 
        siz[i] = 1;    
        fa[i] = 0;     
    }

    while(q--){
        ll query, u, v;
        cin >> query >> u >> v;
        query = 1 + ((query * (1 + Xk) % mod) % 2);
        u = 1 + ((u * (1 + Xk) % mod) % n);
        v = 1 + ((v * (1 + Xk) % mod) % n);
        if(query == 1){
            mergeVert(u, v, parent, siz, fa, g);
        }
        else{
            int ans;
            if(fa[u] == fa[v]) ans = fa[u];
            else if(fa[fa[u]] == v && fa[u] != v) ans = fa[u];
            else if (fa[fa[v]] == u && fa[v] != u) ans = fa[v];
            else ans = 0;

            cout << ans << endl;
            Xk = ans;
        }
    }


    return 0;
}