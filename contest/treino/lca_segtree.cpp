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
int segtree[2*MAXET];
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

void build(int node, int start, int end){
    if(start == end){
        segtree[node] = euler_tour[start];
    } else {
        int mid = (start + end)/2;
        build(2*node + 1, start, mid);
        build(2*node + 2, mid + 1, end);
        int left = segtree[2*node + 1];
        int right = segtree[2*node + 2];
        if(depth[left] < depth[right])
            segtree[node] = left;
        else
            segtree[node] = right;
    }
}

int query(int node, int start, int end, int i, int j){
    if(start > j || end < i)
        return -1;
    if(i <= start && j >= end)
        return segtree[node];
    int mid = (start + end)/2;
    int left = query(2*node + 1, start, mid, i, j);
    int right = query(2*node + 2, mid + 1, end, i, j);
    if(left == -1)
        return right;
    if(right == -1)
        return left;
    if(depth[left] < depth[right])
        return left;
    return right;
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
    return query(0, 0, sz-1, L, R);
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
        build(0, 0, sz-1);
        cout << "Case " << k << ":" << endl;
        cin >> q;
        for(i = 0; i < q; i++){
            cin >> u >> v;
            cout << lca(u, v) << endl;
        }
    }
}