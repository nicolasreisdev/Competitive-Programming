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

ll ans = LMAX;
vector<int> sub;
vector<vector<int>> g;
vector<p> pathSubTree;
vector<ll> melhor;
vector<ll> flag;
int flagAtual = 0;

typedef int T;
class SegTree{
public:
    SegTree(int n){
        mxPos = n - 1;
        t.resize(4 * n, 0);
        lazy.resize(4 * n, 0);
    }

    void build(vector<T> &a, int v, int tl, int tr){
        if (tl == tr){
            t[v] = a[tl];
        }
        else{
            int tm = (tl + tr) / 2;
            build(a, v * 2, tl, tm);
            build(a, v * 2 + 1, tm + 1, tr);
            t[v] = (t[v * 2] + t[v * 2 + 1]);
        }
    }

    void build(vector<T> &a){
        build(a, 1, 0, mxPos);
    }

    void push(int v, int tl, int tr){
        if (lazy[v] != 0){
            int tm = (tl + tr) / 2;
            t[v * 2] += lazy[v] * (tm - tl + 1);
            lazy[v * 2] += lazy[v];
            t[v * 2 + 1] += lazy[v] * (tr - tm);
            lazy[v * 2 + 1] += lazy[v];
            lazy[v] = 0;
        }
    }

    void update(int v, int tl, int tr, int l, int r, T addend){
        if (l > r)
            return;
        if (l == tl && tr == r){
            t[v] += addend * (tr - tl + 1);
            lazy[v] += addend;
        }
        else{
            push(v, tl, tr);
            int tm = (tl + tr) / 2;
            update(v * 2, tl, tm, l, min(r, tm), addend);
            update(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r, addend);
            t[v] = t[v * 2] + t[v * 2 + 1];
        }
    }

    void update(int l, int r, T add){
        update(1, 0, mxPos, l, r, add);
    }

    T query(int v, int tl, int tr, int l, int r){
        if (l > r)
            return 0;
        if (l == tl && r == tr)
            return t[v];
        push(v, tl, tr);
        int tm = (tl + tr) / 2;
        return query(v * 2, tl, tm, l, min(r, tm)) +
               query(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r);
    }

    T query(int l, int r){
        return query(1, 0, mxPos, l, r);
    }

private:
    vector<T> t, lazy;
    int mxPos;
};

vector<bool> roots;
vector<vector<p>> g;
ll ans;
int n, k1, k2;

void dfsAns(int u, int parent, int edges){

    // if (flag[rest] == flagAtual){
    //     ans = min(ans, (ll)edges + melhor[rest]);
    // }

    for (auto &v: g[u]){
        if (v != parent){
            dfsAns(v, u, edges + 1);
        }
    }
}

void dfsMelhor(int u, int parent, int edges){

    if (edges >= k1 && edges <= k2){
        ans++;
        // sumEdges.update(edges, edges, 1); // soma na 
    }

    for (auto &v: g[u]){
        if (v != parent){
            dfsMelhor(v, u, edges + 1);
        }
    }
}

int subTree(int u, int parent){
    sub[u] = 1;

    for (auto& v: g[u])
        if (v != parent)
            sub[u] += subTree(v, u);

    return sub[u];
}

int centroid(int u, int parent, int size){

    for (auto &v : g[u])
        if (v != parent && sub[v] > size / 2)
            return centroid(v, u, size);

    return u;
}

void algorithm(int root){

    int n = subTree(root, -1);
    int newRoot = centroid(root, -1, n); // pega o centroid

    flagAtual++;

    melhor[0] = 0;
    flag[0] = flagAtual;

    for (auto v: g[newRoot]){ // para a subárvore do centroid
        if (!roots[v]){
            dfsAns(v, newRoot,  1);
            dfsMelhor(v, newRoot, 1);
        }
    }

    roots[newRoot] = true;

    for (auto &v : g[newRoot]){
        if (!roots[v]){
            algorithm(v);
        }
    }
}

int main(){
    fastio;
    cin >> n >> k1 >> k2;
    g.assign(n, vector<int>());
    for(int i = 0; i < n-1;i++){
        int u,v; cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }

    // SegTree sumEdges(k2-k1); // intervalo possível de arestas

    algorithm(1);



    return 0;
}