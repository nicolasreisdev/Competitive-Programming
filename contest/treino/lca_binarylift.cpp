#include<bits/stdc++.h>
#define MAXN 1001
#define LOGMAXN 10

using namespace std;

vector<int> tree[MAXN];
int depth[MAXN];
int pai[MAXN][LOGMAXN+1];

void preprocess(int u, int p){
    pai[u][0] = p;
    for(int i = 1; i <= LOGMAXN; i++){
        pai[u][i] = pai[pai[u][i-1]][i-1];
    }
    for(auto adj: tree[u]){
        depth[adj] = depth[u] + 1;
        preprocess(adj, u);
    }
}

int lca(int u, int v){
    if (depth[u] < depth[v]){
        swap(u, v);
    }
    for (int i = LOGMAXN; i >= 0; i--)  
        if ((depth[u] - (1 << i)) >= depth[v])  
            u = pai[u][i];

    if (u == v)  
        return u;  
      
    for (int i = LOGMAXN; i >= 0; i--)  
    {  
        if (pai[u][i] != pai[v][i])  
        {  
            u = pai[u][i];  
            v = pai[v][i];  
        }  
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
        depth[1] = 0;
        preprocess(1, 1);
        cout << "Case " << k << ":" << endl;
        cin >> q;
        for(i = 0; i < q; i++){
            cin >> u >> v;
            cout << lca(u, v) << endl;
        }
    }
}