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

typedef int T;
class SegTree
{
public:
    SegTree(int n)
    {
        mxPos = n - 1;
        t.resize(4 * n, 0);
        lazy.resize(4 * n, 0);
    }

    void build(vector<T> &a, int v, int tl, int tr)
    {
        if (tl == tr)
        {
            t[v] = a[tl];
        }
        else
        {
            int tm = (tl + tr) / 2;
            build(a, v * 2, tl, tm);
            build(a, v * 2 + 1, tm + 1, tr);
            t[v] = (t[v * 2] + t[v * 2 + 1]);
        }
    }

    void build(vector<T> &a)
    {
        build(a, 1, 0, mxPos);
    }

    void push(int v, int tl, int tr)
    {
        if (lazy[v] != 0)
        {
            int tm = (tl + tr) / 2;
            t[v * 2] += lazy[v] * (tm - tl + 1);
            lazy[v * 2] += lazy[v];
            t[v * 2 + 1] += lazy[v] * (tr - tm);
            lazy[v * 2 + 1] += lazy[v];
            lazy[v] = 0;
        }
    }

    void update(int v, int tl, int tr, int l, int r, T addend)
    {
        if (l > r)
            return;
        if (l == tl && tr == r)
        {
            t[v] += addend * (tr - tl + 1);
            lazy[v] += addend;
        }
        else
        {
            push(v, tl, tr);
            int tm = (tl + tr) / 2;
            update(v * 2, tl, tm, l, min(r, tm), addend);
            update(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r, addend);
            t[v] = max(t[v * 2], t[v * 2 + 1]);
        }
    }

    void update(int l, int r, T add)
    {
        update(1, 0, mxPos, l, r, add);
    }

    T query(int v, int tl, int tr, int l, int r)
    {
        if (l > r)
            return 0;
        if (l == tl && r == tr)
            return t[v];
        push(v, tl, tr);
        int tm = (tl + tr) / 2;
        return max(query(v * 2, tl, tm, l, min(r, tm)),
                   query(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r));
    }

    T query(int l, int r)
    {
        return query(1, 0, mxPos, l, r);
    }

private:
    vector<T> t, lazy;
    int mxPos;
};

class Hld
{
public:
    // lista de adjacencia (nao direcionada), valor em cada vertice, qual sera a raiz da arvore
    //
    Hld(vector<vector<int>> &adj, vector<T> &value_, int root = 0) : st(adj.size())
    {

        ct = 0; // marca os vertices com codigo 0,1,2 ... com base na posicao em que vao ficar na seg tree
        int n = adj.size();
        pos = sz = parent = head = depth = vector<int>(n);
        value = value_;

        vector<T> v(n); // vetor com pesos dos vertices na seg tree..
        head[root] = root;
        depth[root] = 0; // vamos considerar que a raiz esta na profundidade 0 (opcional)
        dfs(adj, root, -1);
        build(adj, v, ct, root, -1); // segunda DFS, apos colocar as arestas pesadas como (u, adj[u][0])
        st.build(v);                 // cria a Seg Tree
    }
    // as consultas nas chains sao sempre de cima para baixo
    // note que se o pai de head de v estiver no meio da chain de u --> nao gera problema
    // pois o pos de u sera menor que v e trocariamos os dois..
    // ou seja, sempre teremos  pos[u] >= pos[v]
    // assim, a consulta e sempre do pos maior para o menor...
    T query(int u, int v)
    { // consulta nos nodos do caminho entre vertices u e v
        if (pos[u] < pos[v])
            swap(u, v); // posicoes sao de cima para baixo...
        if (head[u] == head[v])
            return st.query(pos[v], pos[u]); // estao na mesma chain

        // ATUALIZAR (exemplo: minimo de caminho, maximo de caminho, etc)
        // implementacao atual: soma
        return max(st.query(pos[head[u]], pos[u]), query(parent[head[u]], v));
    }

    // soma valor aos vertices ao longo do caminho..
    // void updatePath(int u, int v, T valor){
    //     if (pos[u] < pos[v])
    //         swap(u, v); // posicoes sao de cima para baixo...
    //     if (head[u] == head[v])
    //         st.update(pos[v], pos[u], valor); // estao na mesma chain
    //     else{
    //         st.update(pos[head[u]], pos[u], valor);
    //         updatePath(parent[head[u]], v, valor);
    //     }
    // }
    //! extra!

    // Na dfs, ao processar o nodo u os (sz[u]-1) proximos elementos todos de sua subarvore estarao logo apos ele no vetor v de valores da seg tree
    T querySubtree(int u)
    { // consulta na subarvore inteira do nodo u
        return st.query(pos[u], pos[u] + sz[u] - 1);
    }
    // soma valor a subarvore.
    void updateSubtree(int u, T valor)
    {
        st.update(pos[u], pos[u] + sz[u] - 1, valor);
    }

    int lca(int u, int v)
    {
        if (pos[u] < pos[v])
            swap(u, v);

        if (head[u] == head[v]) // estao na mesma chain...
            return v;
        return lca(parent[head[u]], v);
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
                // o primeiro filho de cada vertice sera sempre o maior
                //(ou seja, tera um heavy edge entre eles)
                if (sz[w] > sz[adj[root][0]] || adj[root][0] == prev)
                    swap(adj[root][0], w);
            }
    }

    // ct = ordem de visitacao dos vertices (comeca de 0)
    // value = peso das arestas, que ficara na seg tree
    void build(vector<vector<int>> &adj, vector<T> &v,
               int &ct, int root, int prev)
    {
        pos[root] = ct;      // onde cada vertice esta na ordem da DFS?
        v[ct] = value[root]; // valor de cada vertice (na ordem da dfs)
        ct++;
        for (int &w : adj[root])
            if (w != prev)
            {                     // vizinhos de root (cuidado para nao voltar)
                parent[w] = root; // pai de cada vertice (para subir)
                // cada vertice e cabeca da sua chain.
                // Depois arrumamos isso para os vertices que estiverem no heavy path
                head[w] = (w == adj[root][0] ? head[root] : w);
                build(adj, v, ct, w, root);
            }
    }

    vector<T> value; // valor armazenado em cada vertice

    int ct;

    vector<int> pos;    // posicao do vertice na seg tree
    vector<int> sz;     // sz[v] e o tamanho da subarvore com raiz em v
    vector<int> parent; // pai de cada vertice
    vector<int> head;   // head (comeco) de cada chain
    vector<int> depth;  // nivel de cada nodo (OPCIONAL, mas pode ser util...)

    SegTree st;
};

int main()
{
    fastio;
    int n;
    cin >> n;
    vector<vector<int>> g(n + 1);
    vector<int> values(n + 1);
    for (int i = 0; i < n - 1; i++)
    {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    Hld hld(g, values, 1);
    int q;
    cin >> q;
    while (q--)
    {
        string query;
        cin >> query;
        if (query == "add")
        {
            int v, x;
            cin >> v >> x;
            hld.updateSubtree(v, x);
        }
        else
        {
            int u, v;
            cin >> u >> v;
            cout << hld.query(u, v) << endl;
        }
    }

    return 0;
}