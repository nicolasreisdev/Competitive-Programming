#include <bits/stdc++.h>
using namespace std;

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

class Hld{
public:
    // lista de adjacencia (nao direcionada)
    // adj[a] --> arestas incidentes em a (pares do tipo vertice, peso)
    Hld(vector<vector<pair<int, int>>> &adj, int root = 0) : st(adj.size()){
        ct = 0; // marca os vertices com codigo 0,1,2 ... com base na posicao em que vao ficar na seg tree
        int n = adj.size();
        pos = sz = parent = head = depth = vector<int>(n);

        vector<T> v(n); // vetor com pesos dos vertices na seg tree..
        head[root] = root;
        depth[root] = 0; // vamos considerar que a raiz esta na profundidade 0 (opcional)
        dfs(adj, root, -1);
        build(adj, v, ct, root, -1, -1); // segunda DFS, após colocar as arestas pesadas como (u, adj[u][0])
        st.build(v);                     // cria a Seg Tree
    }
    // as consultas nas chains sao sempre de cima para baixo
    // note que se o pai de head de v estiver no meio da chain de u --> nao gera problema
    // pois o pos de u será menor que v e trocariamos os dois..
    // ou seja, sempre teremos  pos[u] >= pos[v]
    // assim, a consulta é sempre do pos maior para o menor...
    T query(int u, int v){ // consulta nos nodos do caminho entre vertices u e v
        if (pos[u] < pos[v])
            swap(u, v); // posicoes sao de cima para baixo...
        if (head[u] == head[v])
            return st.query(pos[v] + 1, pos[u]); // estao na mesma chain

        // ATUALIZAR (exemplo: minimo de caminho, maximo de caminho, etc)
        // implementacao atual: soma
        return st.query(pos[head[u]], pos[u]) + query(parent[head[u]], v);
    }
    // soma valor ao caminho..
    void updatePath(int u, int v, T valor){
        if (u == v)
            return; // se o caminho tem apenas 1 vertice --> nao ha aresta para atualizar...
        if (pos[u] < pos[v])
            swap(u, v); // posicoes sao de cima para baixo...
        if (head[u] == head[v])
            st.update(pos[v] + 1, pos[u], valor); // estao na mesma chain
        else{
            st.update(pos[head[u]], pos[u], valor); // atualiza de head[u] até pos[u] com o valor
            updatePath(parent[head[u]], v, valor);
        }
    }

    //! extra!

    // Na dfs, ao processar o nodo u os (sz[u]-1) proximos elementos todos de sua subarvore estarao logo apos ele no vetor v de valores da seg tree
    T querySubtree(int u){ // consulta na subarvore inteira do nodo u
        if (sz[u] == 1)
            return 0; // árvore com 1 vertice nao tem aresta --> peso 0
        return st.query(pos[u] + 1, pos[u] + sz[u] - 1);
    }
    // soma valor a subarvore..
    void updateSubtree(int u, T valor){
        if (sz[u] == 1)
            return;
        st.update(pos[u] + 1, pos[u] + sz[u] - 1, valor);
    }
    int lca(int u, int v){
        if (pos[u] < pos[v])
            swap(u, v);

        if (head[u] == head[v]) // estao na mesma chain...
            return v;
        return lca(parent[head[u]], v);
    }

private:
    void dfs(vector<vector<pair<int, int>>> &adj, int root, int prev){
        sz[root] = 1;
        for (auto &vizinho : adj[root])
            if (vizinho.first != prev){
                auto &[w, peso] = vizinho;
                depth[w] = depth[root] + 1; // opcional
                dfs(adj, w, root);
                sz[root] += sz[w];
                if (sz[w] > sz[adj[root][0].first] || adj[root][0].first == prev)
                    swap(adj[root][0], vizinho); // o primeiro filho de cada vértice será sempre o maior (ou seja, terá um heavy edge entre eles)
            }
    }
    // ct = ordem de visitacao dos vertices (comeca de 0)
    // value = peso das arestas, que ficara na seg tree
    void build(vector<vector<pair<int, int>>> &adj, vector<T> &v,
               int &ct, int root, int valorAresta, int prev){
        pos[root] = ct;
        v[ct] = valorAresta;
        ct++;
        for (auto &[w, peso] : adj[root])
            if (w != prev){ // vizinhos de root
                parent[w] = root;
                // cada vertice é cabeca da sua chain.
                // Depois arrumamos isso para os vertices que estiverem no heavy path
                head[w] = (w == adj[root][0].first ? head[root] : w);
                build(adj, v, ct, w, peso, root);
            }
    }

    int ct;

    vector<int> pos;    // posicao do vertice na seg tree
    vector<int> sz;     // sz[v] é o tamanho da subarvore com raiz em v
    vector<int> parent; // pai de cada vertice
    vector<int> head;   // head (começo) de cada chain
    vector<int> depth;  // nivel de cada nodo (OPCIONAL, mas pode ser util...)

    SegTree st;
};

int main(){

    int n, m; cin >> n >> m;
    vector<vector<pair<int, int>>> g(n+1);
    for(int i = 2; i <= n;i++){
        int u, v; cin >> u >> v;    
        g[u].push_back({v, 0});
        g[v].push_back({u, 0});
    }

    Hld hld(g, 1);

    while(m--){
        string query; cin >> query;
        int u, v; cin >> u >> v;    
        if(query == "P"){
            hld.updatePath(u, v, 1);
        }else{
            cout << hld.query(u, v) << endl;
        }
    }

    return 0;
}