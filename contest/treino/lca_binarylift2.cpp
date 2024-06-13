#include<bits/stdc++.h>
#define MAXN 1001
#define LOGMAXN 10

using namespace std;

vector<int> tree[MAXN];
int pai[MAXN][LOGMAXN+1];
int timer;
int tin[MAXN], tout[MAXN];

void preprocess(int u, int p){
    tin[u] = ++timer;
    pai[u][0] = p;
    for(int i = 1; i <= LOGMAXN; i++){
        pai[u][i] = pai[pai[u][i-1]][i-1];
    }
    for(auto adj: tree[u]){
        preprocess(adj, u);
    }
    tout[u] = ++timer;
}

bool is_ancestor(int u, int v){
    return tin[u] <= tin[v] && tout[u] >= tout[v];
}

int lca(int u, int v){
    if (is_ancestor(u, v))
        return u;
    if (is_ancestor(v, u))
        return v;
    for (int i = LOGMAXN; i >= 0; i--) {
        if (!is_ancestor(pai[u][i], v))
            u = pai[u][i];
    }
    return pai[u][0];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t, k, i, j, n, m, q, u, v;
    cin >> t;
    for(k = 1; k <= t; k++){
        cin >> n;
        for(i = 1; i <= n; i++){
            tree[i].clear();
            cin >> m;
            for(j = 0; j < m; j++){
                cin >> u;
                tree[i].push_back(u);
            }
        }
        timer = 0;
        preprocess(1, 1);
        cout << "Case " << k << ":" << endl;
        cin >> q;
        for(i = 0; i < q; i++){
            cin >> u >> v;
            cout << lca(u, v) << endl;
        }
    }
}