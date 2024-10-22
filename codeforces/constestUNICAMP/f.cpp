#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define endl '\n'
#define pb push_back
#define rm pop_back
#define f first
#define s second
#define sz size
#define in insert

typedef long long ll;
typedef pair<int, ll> p;
const int MAX = 0x3f3f3f3f;
const ll LMAX = 0x3f3f3f3f3f3f3f3f;

struct dsu{
    vector<int> parent, size;
    dsu(int n){
        parent.resize(n);                      // Vetor de pais
        size.resize(n, 1);                     // Vetor de tamanho
        iota(parent.begin(), parent.end(), 0); // Inicializa o vetor de pais
    }

    int find(int x){
        return parent[x] == x ? x : parent[x] = find(parent[x]); // Path compression
    }

    void unite(int x, int y){
        x = find(x);
        y = find(y);
        if (x != y){
            if (size[x] < size[y])
                swap(x, y); // por tamanho
            parent[y] = x;
            size[x] += size[y];
        }
    }

    bool same(int x, int y){
        return find(x) == find(y);
    }

    int get_size(int x){
        return size[find(x)];
    }
};


vector<vector<p>> kruskal(vector<vector<ll>> &g, int n, ll init){
    dsu dsu(n);  // Inicializa a DSU
    ll cost = 0; // Custo total da MST
    vector<vector<p>> mst(n+2);
    sort(g.begin(), g.end());
    for (auto edges : g){
        ll w = edges[0];
        ll x = edges[1];
        ll y = edges[2];
        if (!dsu.same(x, y)){ // Se nao forma ciclo (x e y nao estao na mesma componente), isso serve para percorrermos todas as arestas e nao formar ciclos
            dsu.unite(x, y);
            cost += w;
            mst[x].pb({y, w});
            mst[y].pb({x, w});
        }
    }
}


void dfs(vector<vector<p>> &g, int x, int p, ll sum, vector<int> &pos){
    for(auto [v, w]: g[x]){
        if(v == p) continue;
        pos.pb(v);
        sum += w;
        dfs(g, v, x, sum, pos);
        sum += w;
        pos.pb(x);
    }
    cout << sum << endl;
}


int main(){
    fastio;
    int n, m; cin >> n >> m;
    vector<vector<ll>> g1;
    ll ans = 0;
    for(int i = 0; i < m;i++){
        int a, b, c; cin >> a >> b >> c;
        g1.pb({c, a, b});
        g1.pb({c, b, a});
    }
    vector<vector<p>> mst = kruskal(g1, n, 1);
    vector<ll> dist(n+2, LMAX);
    ll sum = 0;
    vector<int> pos;
    dfs(mst, 1, -1, sum, pos);

    for(int i = 0; i < pos.size();i++){
        cout << pos[i] << " ";
    }

    return 0;
}