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
// #define sz size
#define in insert

typedef pair<int, int> p;
typedef long long ll;
const int MAX = 0x3f3f3f3f;
const ll LMAX = 0x3f3f3f3f3f3f3f3f;

typedef int T;
class SegTree{
public:
    SegTree(int n){
        mxPos = n - 1;
        t.resize(4 * n);
    }

    T combine(T a, T b){
        if (a > b)
            return a;
        if (b > a)
            return b;
        return a;
    }

    // constroi a segTree com os elementos de a
    // inicialmente, tl=0, tr=n-1
    void build(vector<int> &a, int tl, int tr, int v){
        if (tl == tr){// folha
            t[v] = a[tl]; // adaptar
        }
        else{
            int tm = (tl + tr) / 2; // meio do segmento
            // constroi nodos da esquerda ([tl,tm])
            build(a, tl, tm, v * 2);
            // constroi nodos da direita ([tm+1,tr])
            build(a, tm + 1, tr, v * 2 + 1);
            // junta o resultado dos segmentos da esquerda e direita
            // em geral, aqui é lugar mais "adaptado"
            t[v] = combine(t[v * 2], t[v * 2 + 1]);
        }
    }
    void build(vector<int> &a){
        build(a, 0, mxPos, 1);
    }

    // consulta para encontrar a soma do intervalo [l,r]
    // procura no vértice v, representando os intervalos
    //[tl,tr] (na árvore)
    T query(int v, int tl, int tr, int l, int r){
        if (l > r)
            return -MAX; // adaptar, caso outro tipo de consulta
        if (l == tl && r == tr){
            return t[v];
        }
        int tm = (tl + tr) / 2;

        // chama SEMPRE para os dois lados
        // mesmo se desnecessário --> ok (primeiro if)
        // adaptar, caso outro tipo de consulta
        return combine(query(v * 2, tl, tm, l, min(r, tm)),
                       query(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r));
    }
    T query(int l, int r){
        return query(1, 0, mxPos, l, r);
    }

    // nesse caso, new_val é inteiro
    void update(int v, int tl, int tr, int pos, int new_val){
        if (tl == tr){
            t[v] = new_val;
        }
        else{
            int tm = (tl + tr) / 2;
            if (pos <= tm) // nodo está na esquerda?
                update(v * 2, tl, tm, pos, new_val);
            else // nodo está na direita?
                update(v * 2 + 1, tm + 1, tr, pos, new_val);

            // atualiza raiz atual
            // adaptar, caso outro tipo de consulta
            t[v] = combine(t[v * 2], t[v * 2 + 1]);
        }
    }
    void update(int pos, int new_val){
        update(1, 0, mxPos, pos, new_val);
    }

private:
    vector<T> t;
    int mxPos;
};

class Hld{
public:
    // lista de adjacencia (nao direcionada), valor em cada vertice, qual será a raiz da árvore
    //
    Hld(vector<vector<int>> &adj, vector<int> &value_, int root = 0) : st(adj.size()){
        ct = 0; // marca os vertices com codigo 0,1,2 ... com base na posicao em que vao ficar na seg tree
        int n = adj.size();
        pos = sz = parent = head = depth = vector<int>(n);
        value = value_;

        vector<int> v(n); // vetor com pesos dos vertices na seg tree..
        head[root] = root;
        depth[root] = 0; // vamos considerar que a raiz esta na profundidade 0 (opcional)
        dfs(adj, root, -1);
        build(adj, v, ct, root, -1); // segunda DFS, após colocar as arestas pesadas como (u, adj[u][0])
        st.build(v);                 // cria a Seg Tree
    }
    // as consultas nas chains sao sempre de cima para baixo
    // note que se o pai de head de v estiver no meio da chain de u --> nao gera problema
    // pois o pos de u será menor que v e trocariamos os dois..
    // ou seja, sempre teremos  pos[u] >= pos[v]
    // assim, a consulta é sempre do pos maior para o menor...
    int query(int u, int v){ // consulta nos nodos do caminho entre vertices u e v
        if (pos[u] < pos[v])
            swap(u, v); // posicoes sao de cima para baixo...
        if (head[u] == head[v])
            return st.query(pos[v], pos[u]); // estao na mesma chain

        return max(st.query(pos[head[u]], pos[u]), query(parent[head[u]], v)); // retorna o maior valor 
    }

    void updateVertice(int v, int valor){
        st.update(pos[v], valor);
    }

private:
    // prev = nodo anterior na DFS (pai)
    void dfs(vector<vector<int>> &adj, int root, int prev){
        sz[root] = 1;
        // w TEM que ser por referencia (por causa do swap!!!)
        for (int &w : adj[root])
            if (w != prev){
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
    void build(vector<vector<int>> &adj, vector<int> &v,
               int &ct, int root, int prev){
        pos[root] = ct;      // onde cada vértice está na ordem da DFS?
        v[ct] = value[root]; // valor de cada vértice (na ordem da dfs)
        ct++;
        for (int &w : adj[root])
            if (w != prev){ // vizinhos de root (cuidado para nao voltar)
                parent[w] = root; // pai de cada vértice (para subir)
                // cada vertice é cabeca da sua chain.
                // Depois arrumamos isso para os vertices que estiverem no heavy path
                head[w] = (w == adj[root][0] ? head[root] : w);
                build(adj, v, ct, w, root);
            }
    }

    vector<int> value; // valor armazenado em cada vertice

    int ct;

    vector<int> pos;    // posicao do vertice na seg tree
    vector<int> sz;     // sz[v] é o tamanho da subarvore com raiz em v
    vector<int> parent; // pai de cada vertice
    vector<int> head;   // head (começo) de cada chain
    vector<int> depth;  // nivel de cada nodo (OPCIONAL, mas pode ser util...)

    SegTree st;
};


int main(){
    fastio;
    int n, q; cin >> n >> q;
    vector<int> value(n+1);
    for(int i = 1; i <= n;i++){
        cin >> value[i];
    }
    vector<vector<int>> g(n+1);
    for(int i = 1; i < n;i++){
        int u, v;cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    
    Hld hld(g, value, 1);

    for(int i = 0; i < q;i++){
        int query; cin >> query;
        if(query == 1){
            int v, x; cin >> v >> x;
            //update vertice v -> x;
            hld.updateVertice(v, x);
        }else{
            int u, v; cin >> u >> v;
            // max do caminho dos nodos u v;
            cout << hld.query(u, v) << " ";
        }
    }

    return 0;
}
