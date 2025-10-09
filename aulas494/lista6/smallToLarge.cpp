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


vector<int> ans;

set<int> dfs(vector<vector<int>> &g, vector<int> &colors, int u, int parent){
    
    set<int> coresU;
    coresU.insert(colors[u]);

    for(auto &v: g[u]){
        if(v != parent) {
            set<int> coresChild = dfs(g, colors, v, u);
            if(coresChild.size() > coresU.size()) swap(coresChild, coresU);
            for(auto &c: coresChild) coresU.insert(c);
        }
    }

    ans[u] = coresU.size();
    return coresU;
}


int main(){
    fastio;

    int n; cin >> n;
    vector<int> colors(n);
    ans.resize(n);
    vector<vector<int>> g(n, vector<int>());
    for(int i = 0; i < n;i++) cin >> colors[i];

    for(int i = 0; i < n-1;i++){
        int u, v; cin >> u >> v;
        u--; v--;
        g[u].pb(v);
        g[v].pb(u);
    }

    dfs(g, colors, 0, -1);

    for(auto &resp: ans) cout << resp << " ";
    cout << endl;


    return 0;
}