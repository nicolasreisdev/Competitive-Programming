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
// #define s second
#define sz size
#define in insert

typedef pair<int, int> p;
typedef long long ll;
const int MAX = 0x3f3f3f3f;
const ll LMAX = 0x3f3f3f3f3f3f3f3f;

vector<ll> bitMask(vector<vector<ll>> &adj, ll start, ll end){
    ll mask;
    vector<ll> sub(end-start);
    for (int j = start; j < end; j++){
        for (int v : adj[j]){
            mask += 1 << v;
        }
        sub.pb(mask);
    }
    for(int i = start; i < end;i++){
        for(int j = start; j < end;j++){
            if(checkIndependentSet(adj[i], end-start, sub[i] & sub[j])) sub[i] = (sub[i] | sub[j]);
        }
    }
    return sub;
}







bool checkIndependentSet(vector<ll> &adj, ll n, ll mask){
    for(int i = 0; i < n;i++){
        if(!(1<<mask)) continue; // se não esta na mascara continua
        if((adj[i] & mask)) return false; //
    }
    return true;
}



int main(){
    fastio;

    int n, m;
    cin >> n >> m;
    vector<vector<ll>> adj(n);
    for (int i = 0; i < m; i++){
        ll u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    vector<ll> sub1 = bitMask(adj, 0, n/2);
    vector<ll> sub2 = bitMask(adj, n/2, n);

    for(int i = 0; i < sub1.size();i++){
        for(int j = 0; j < sub2.size();i++){
            
        }
    }

    return 0;
}