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
const ll mod = 1e9+7;

void dfs(int u, int parent, vector<vector<int>> &g, vector<vector<ll>> &dp){
    dp[u][0] = 1;
    dp[u][1] = 1;
    for(auto v: g[u]){
        if(v == parent) continue;
        dfs(v, u, g, dp);
        dp[u][0] = (dp[u][0] * (dp[v][0] + dp[v][1])) % mod;
        dp[u][1] = (dp[u][1] * dp[v][0]) % mod;
    }
}

int main(){
    fastio;

    int n; cin >> n;
    vector<vector<int>> g(n+1);
    vector<vector<ll>> dp(n+1, vector<ll>(2)); 
    for(int i = 0; i < n-1; i++){
        int u, v; cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u); 
    }
    
    dfs(1, -1, g, dp);
    ll ans = (dp[1][0] + dp[1][1]) % mod;
    cout << ans << endl;
    
    return 0;
}