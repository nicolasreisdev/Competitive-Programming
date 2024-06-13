#include<bits/stdc++.h>
#define MAXN 1001

using namespace std;

vector<int> tree[MAXN];
int depth[MAXN];
int pai[MAXN];

void preprocess_depth(int u, int d){
    depth[u] = d;
    for(auto adj : tree[u]){
        preprocess_depth(adj, d + 1);
    }
}

int lca(int u, int v){
    if (depth[u] < depth[v]){
        swap(u, v);
    }
    while(depth[u] > depth[v]){
        u = pai[u];
    }
    while(u != v){
        u = pai[u];
        v = pai[v];
    }
    return u;
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
                pai[u] = i;
                tree[i].push_back(u);
            }
        }
        preprocess_depth(1, 0);
        cout << "Case " << k << ":" << endl;
        cin >> q;
        for(i = 0; i < q; i++){
            cin >> u >> v;
            cout << lca(u, v) << endl;
        }
    }
}