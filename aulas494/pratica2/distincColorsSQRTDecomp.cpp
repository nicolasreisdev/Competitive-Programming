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
#define in insert

typedef long long ll;
typedef pair<ll, ll> p;
const int MAX = 1e6 + 10;
const ll LMAX = 0x3f3f3f3f3f3f3f3f;

const int SQ = sqrt(MAX);
ll v[MAX];

ll ans, freq[MAX];

inline void insert(int p){
    int o = v[p];
    if(freq[o] == 0) ans++;
    freq[o]++;
}

inline void erase(int p){
    int o = v[p];
    freq[o]--;
    if(freq[o] == 0) ans--;
}

inline ll hilbert(ll x, ll y){
    static int N = 1 << (__builtin_clz(0) - __builtin_clz(MAX));
    int rx, ry, s;
    ll d = 0;
    for (s = N / 2; s > 0; s /= 2)
    {
        rx = (x & s) > 0, ry = (y & s) > 0;
        d += s * ll(s) * ((3 * rx) ^ ry);
        if (ry == 0)
        {
            if (rx == 1)
                x = N - 1 - x, y = N - 1 - y;
            swap(x, y);
        }
    }
    return d;
}

#define HILBERT true
vector<ll> MO(vector<pair<ll, ll>> &q){
    ans = 0;
    int m = q.size();
    vector<ll> ord(m);
    iota(ord.begin(), ord.end(), 0);
#if HILBERT
    vector<ll> h(m);
    for (int i = 0; i < m; i++)
        h[i] = hilbert(q[i].first, q[i].second);
    sort(ord.begin(), ord.end(), [&](int l, int r)
         { return h[l] < h[r]; });
#else
    sort(ord.begin(), ord.end(), [&](int l, int r)
         {
		if (q[l].first / SQ != q[r].first / SQ) return q[l].first < q[r].first;
		if ((q[l].first / SQ) % 2) return q[l].second > q[r].second;
		return q[l].second < q[r].second; });
#endif
    vector<ll> ret(m);
    int l = 0, r = -1;

    for (int i : ord)
    {
        int ql, qr;
        tie(ql, qr) = q[i];
        while (r < qr)
            insert(++r);
        while (l > ql)
            insert(--l);
        while (l < ql)
            erase(l++);
        while (r > qr)
            erase(r--);
        ret[i] = ans;
    }
    return ret;
}

typedef int T;

class Hld
{
public:
    // lista de adjacencia (nao direcionada), valor em cada vertice, qual será a raiz da árvore
    //
    Hld(vector<vector<int>> &adj, vector<T> &value_, int root = 0){

        ct = 0; // marca os vertices com codigo 0,1,2 ... com base na posicao em que vao ficar na seg tree
        int n = adj.size();
        pos = sz = parent = head = depth = vector<int>(n);
        value = value_;

        vector<T> vec(n); // vetor com pesos dos vertices na seg tree..
        head[root] = root;
        depth[root] = 0; // vamos considerar que a raiz esta na profundidade 0 (opcional)
        dfs(adj, root, -1);
        build(adj, vec, ct, root, -1); // segunda DFS, após colocar as arestas pesadas como (u, adj[u][0])

        map<int, int> comp;
        int next = 0; // quantidade de cores
        for (int i = 0; i < n; i++){
            if (comp.find(vec[i]) == comp.end()){
                comp[vec[i]] = next++;
            }
        }
        for (int i = 0; i < n; i++){
            v[i] = comp[vec[i]]; // id de cada cor
        }

        vector<p> queries;
        for(int i = 0; i < n;i++){
            queries.pb({pos[i], pos[i] + sz[i]-1});
        }

        vector<ll> result = MO(queries);
        for(auto &e: result) cout << e << " ";
    }


private:
    // prev = nodo anterior na DFS (pai)
    void dfs(vector<vector<int>> &adj, int root, int prev)
    {
        sz[root] = 1;
        // w TEM que ser por referencia (por causa do swap!!!)
        for (int &w : adj[root])
            if (w != prev)
            {
                depth[w] = depth[root] + 1; // opcional
                dfs(adj, w, root);
                sz[root] += sz[w];
                // o primeiro filho de cada vértice será sempre o maior
                //(ou seja, terá um heavy edge entre eles)
                if (sz[w] > sz[adj[root][0]] || adj[root][0] == prev)
                    swap(adj[root][0], w);
            }
    }

    // ct = ordem de visitacao dos vertices (comeca de 0)
    // value = peso das arestas, que ficara na seg tree
    void build(vector<vector<int>> &adj, vector<T> &v,
               int &ct, int root, int prev)
    {
        pos[root] = ct;      // onde cada vértice está na ordem da DFS?
        v[ct] = value[root]; // valor de cada vértice (na ordem da dfs)
        ct++;
        for (int &w : adj[root])
            if (w != prev)
            {                     // vizinhos de root (cuidado para nao voltar)
                parent[w] = root; // pai de cada vértice (para subir)
                // cada vertice é cabeca da sua chain.
                // Depois arrumamos isso para os vertices que estiverem no heavy path
                head[w] = (w == adj[root][0] ? head[root] : w);
                build(adj, v, ct, w, root);
            }
    }

    vector<T> value; // valor armazenado em cada vertice

    int ct;

    vector<int> pos;    // posicao do vertice na seg tree
    vector<int> sz;     // sz[v] é o tamanho da subarvore com raiz em v
    vector<int> parent; // pai de cada vertice
    vector<int> head;   // head (começo) de cada chain
    vector<int> depth;  // nivel de cada nodo (OPCIONAL, mas pode ser util...)

};

int main(){
    int n;
    cin >> n;

    vector<vector<int>> g(n);
    vector<int> color(n);
    for(int i = 0; i < n;i++) cin >> color[i];
    for(int i = 0; i < n-1;i++){
        int u, v; cin >> u >> v;
        u--;v--;
        g[u].pb(v);
        g[v].pb(u);
    }

    Hld hld(g, color);
   
}