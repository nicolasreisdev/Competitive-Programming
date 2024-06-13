#include<bits/stdc++.h>
#define MAXN 1001
#define LOGMAXN 11
#define MAXET 2002

using namespace std;

vector<int> tree[MAXN];
int visited[MAXN];
int euler_tour[MAXET];
int sz; //Size of euler_tour
int first[MAXN]; //Primeira ocorrência do nó em euler_tour
int depth[MAXN];
int st[MAXET][LOGMAXN+1];
int logN[MAXET+1];

void init(){
    memset(visited, 0, sizeof(visited));
    sz = 0;
}

void preprocess_log(){
    logN[1] = 0;
    for(int i = 2; i <= MAXET; i++)
        logN[i] = logN[i/2] + 1;
}

int f(int x, int y){
    if (depth[x] < depth[y])
        return x;
    return y;
}

void build(int v[], int n)
{
    for(int i = 0; i < n; i++)
        st[i][0] = v[i];
    for(int j = 1; j <= LOGMAXN; j++){
        for(int i = 0; i + (1 << j) <= MAXET; i++)
        {
            st[i][j] = f(st[i][j-1], st[i + (1 << (j-1))][j-1]);
        }
    }
}

int query(int L, int R){
    int j = logN[R - L + 1];
    return f(st[L][j], st[R - (1 << j) + 1][j]);
}


void preprocess(int u, int d){
    visited[u] = 1;
    depth[u] = d;
    first[u] = sz;
    euler_tour[sz++] = u;

    for(auto adj:tree[u]){
        if(!visited[adj]){
            preprocess(adj, d+1);
            euler_tour[sz++] = u;
        }
    }
}

int lca(int u, int v){
    int L = first[u];
    int R = first[v];
    if (R < L)
        swap(L, R);
    return query(L, R);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t, k, i, j, n, m, q, u, v;
    preprocess_log();

    cin >> t;
    for(k = 1; k <= t; k++){
        init();
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
        preprocess(1, 0);
        build(euler_tour, sz);
        cout << "Case " << k << ":" << endl;
        cin >> q;
        for(i = 0; i < q; i++){
            cin >> u >> v;
            cout << lca(u, v) << endl;
        }
    }
}