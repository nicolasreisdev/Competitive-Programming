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

int timer = 0;

template <typename T>
class SparseTable{
private:
    int n, log2dist;
    vector<vector<T>> st;

public:
    SparseTable(const vector<T> &v){
        n = (int)v.size();
        log2dist = 1 + (int)log2(n);
        st.resize(log2dist);
        st[0] = v;
        for (int i = 1; i < log2dist; i++){
            st[i].resize(n - (1 << i) + 1);
            for (int j = 0; j + (1 << i) <= n; j++){
                st[i][j] = min(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]);
            }
        }
    }

    /** @return minimum on the range [l, r] */
    T query(int l, int r){
        int i = (int)log2(r - l + 1);
        return min(st[i][l], st[i][r - (1 << i) + 1]);
    }
};

// LCA usando euler tour
// fonte: https://usaco.guide/gold/tree-euler?lang=cpp
// assume que 0 é a raiz...
class LCA{
private:
    const int n;
    const vector<vector<int>> &adj;
    SparseTable<pair<int, int>> rmq;
    vector<int> tin, et, dep, tout;
    vector<vector<int>> distDep;
    int timer = 0;

    /** prepares tin, et, dep arrays */
    void dfs(int u, int p){
        tin[u] = timer;  // tempo de entrada do vertice
        et[timer++] = u; // adiciona os vertices na ordem do euler tour
        for (int v : adj[u]){
            if (v == p){
                continue;
            }
            dep[v] = dep[u] + 1;
            dfs(v, u);
            //et[timer++] = u; // não entendi o motivo dessa linha.
        }
        tout[u] = timer;
    }

public:
    // make sure the adjacency list is 0 indexed
    LCA(vector<vector<int>> &_adj)
        : n((int)_adj.size()), adj(_adj), tin(n), et(n), dep(n),
          rmq(vector<pair<int, int>>(1)), distDep(n), tout(n)
    {
        dfs(0, -1);
        vector<pair<int, int>> arr(n);
        for (int i = 0; i < n; i++)
        {
            arr[i] = {dep[et[i]], et[i]};
        }
        rmq = SparseTable<pair<int, int>>(arr);

        for (auto &[h, et] : arr){
            // cout << h << " " << et << endl;
            distDep[h].push_back(tin[et]);
        }
        for (int i = 0; i < distDep.size(); i++)
        {
            sort(distDep[i].begin(), distDep[i].end());
        }

    }

    /** @return LCA of nodes a and b */
    int query(int a, int b){
        if (tin[a] > tin[b]){
            swap(a, b);
        }
        return rmq.query(tin[a], tin[b]).second;
    }

    int querySum(int v, int dist){
        auto l = lower_bound(distDep[dist].begin(), distDep[dist].end(), tin[v-1]);
        auto r = lower_bound(distDep[dist].begin(), distDep[dist].end(), tout[v-1]);
        return r-l;
    }

    void debug(){
        for (int i = 0; i < n; i++)
            cout << i << " ";
        cout << endl;
        for (int i = 0; i < n; i++)
            cout << tin[i] << " ";
        cout << endl;
        for (int i = 0; i < n; i++)
            cout << tout[i] << " ";
        cout << endl;
        for (int i = 0; i < n; i++)
            cout << dep[i] << " ";
        cout << endl;

        cout << endl;
        for (int i = 0; i < et.size(); i++)
            cout << i << " ";
        cout << endl;
        for (int i = 0; i < et.size(); i++)
            cout << dep[et[i]] << " ";
        cout << endl;
        for (int i = 0; i < et.size(); i++)
            cout << et[i] << " ";
        cout << endl;
        for(int i = 0; i < distDep.size();i++){
            cout << "dep " << i << ": ";
            for(auto &start: distDep[i]) cout << start << " ";
            cout << endl;
        }
    }
};



int main(){
    fastio;
    int n; cin >> n;
    vector<vector<int>> g(n);
    for(int i = 1; i < n;i++){
        int parent; cin >> parent;
        g[parent-1].push_back(i);
    }
    LCA lca(g);
    //lca.debug();
    int q; cin >> q;
    for(int i = 0;i < q;i++){
        int u, d; cin >> u >> d;
        cout << lca.querySum(u, d) << endl;
    }

    return 0;
}