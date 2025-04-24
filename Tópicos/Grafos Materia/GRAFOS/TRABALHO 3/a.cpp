/*
README
Aluno: Nicolas Eliel dos Reis Silva - Matrícula: 112703
Fontes de consulta: nenhuma, apenas pergunta ao professor sobre a questão.
*/

#include <bits/stdc++.h>
using namespace std;

// #define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define endl '\n'
#define pb push_back
#define rm pop_back
#define f first
#define s second
#define sz size
#define in insert

typedef pair<int, int> p;
typedef long long ll;
const int MAX = 2 * 1e5;
const ll LMAX = 0x3f3f3f3f3f3f3f3f;

class UnionFind{
public:
    void createset(int n){
        parent.resize(n);
        for (int i = 0; i < n; i++){
            parent[i] = i;
        }
    }

    int find(int x){
        return parent[x] == x ? x : parent[x] = find(parent[x]); // path compression
    }

    bool same(int x, int y){
        return find(x) == find(y);
    }

    void unite(int x, int y){
        parent[find(x)] = find(y);
    }

private:
    vector<int> parent;
};

void tarjan(int parent, const vector<vector<int>> &adj, vector<int> &dfsParent, vector<int> &dfsNum,
            vector<int> &dfsLow, vector<bool> &isArticulation, vector<pair<int, int>> &bridges,
            int &dfsCount, int &rootChildren, int dfsRoot, UnionFind &dsu){
    dfsLow[parent] = dfsNum[parent] = ++dfsCount; // dfsLow[u] <= dfsNum[u]
    for (int  son: adj[parent]){
        // vertices nao descobertos tem tempo de descoberto (dfsNum) 0
        if (dfsNum[son] == 0){
            dfsParent[son] = parent; // pai de v e' u (v foi descoberto por u)
            if (parent == dfsRoot) // caso especial... precisamos contar quantas vezes descobrimos vertices a partir da raiz para descobrir se raiz e' articulacao...
                rootChildren++;

            tarjan(son, adj, dfsParent, dfsNum, dfsLow, isArticulation, bridges, dfsCount, rootChildren, dfsRoot, dsu);

            if (dfsLow[son] >= dfsNum[parent])   // apos visitar v recursivamente, conseguimos chegar em um vertice em v ou antes passando por u? (sem voltar pela aresta v,u)
                isArticulation[parent] = true; // store this information first
            if (dfsLow[son] > dfsNum[parent]){    // ponte?
                bridges.push_back(make_pair(parent, son));
                dsu.unite(parent, son);
                //cout << u << v << endl;
            }
            dfsLow[parent] = min(dfsLow[parent], dfsLow[son]); // update dfsLow[u]
        }
        else if (son != dfsParent[parent])                // cheguei de volta em um vertice ja descoberto... se nao passei pela aresta v,u de volta --> ciclo...
            dfsLow[parent] = min(dfsLow[parent], dfsNum[son]); // atualize dfsLow...
    }
}

void tarjan(const vector<vector<int>> &adj,
            vector<bool> &isArticulation, vector<pair<int, int>> &bridges, UnionFind &dsu){
    int nv = adj.size();
    isArticulation = vector<bool>(nv, false);
    bridges.resize(0);

    vector<int> dfsParent(nv, -1);
    vector<int> dfsLow(nv, 0);
    vector<int> dfsNum(nv, 0);
    int dfsCount = 0;

    // para multiplos CCs ...
    for (int i = 0; i < nv; i++){
        if (dfsNum[i] == 0){
            int rootChildren = 0; // resete para cada CC!!
            tarjan(i, adj, dfsParent, dfsNum, dfsLow, isArticulation, bridges, dfsCount, rootChildren, i, dsu);
            isArticulation[i] = rootChildren > 1;
        }
    }
}

int main(){
    // fastio;
    int n, m, c;
    cin >> n >> m >> c;
    while (n != 0 || m != 0 || c != 0){

        vector<vector<int>> g(n+1);
        UnionFind dsu;
        dsu.createset(n+1);
        for (int i = 0; i < m; i++){
            int a, b; cin >> a >> b;
            g[a].pb(b);
            g[b].pb(a);
        }
        vector<bool> isArticulation;
        vector<p> bridge;
        tarjan(g, isArticulation, bridge, dsu);
        for (int i = 0; i < c; i++){
            int a, b;
            cin >> a >> b;
            if (!dsu.same(a, b))
                cout << "N" << endl; // caso b tenha mais que 2 caminhos ou a e b não estejam no mesmo componente conexo
            else
                cout << "Y" << endl;
        }
        cout << "-" << endl;
        cin >> n >> m >> c;
    }

    return 0;
}