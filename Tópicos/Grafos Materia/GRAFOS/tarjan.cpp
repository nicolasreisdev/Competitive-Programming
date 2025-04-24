/*
README
Aluno: Nicolas Eliel dos Reis Silva - Matrícula: 112703
Fontes de consulta: nenhuma.
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
const int MAX = 0x3f3f3f3f;
const ll LMAX = 0x3f3f3f3f3f3f3f3f;

void tarjan(int parent, const vector<vector<int>> &adj, vector<int> &dfsParent, vector<int> &dfsDisc,
            vector<int> &dfsLow, vector<bool> &isArticulation, vector<pair<int, int>> &bridges,
            int &dfsCount, int &rootChildren, int dfsRoot){
    dfsLow[parent] = dfsDisc[parent] = ++dfsCount; // dfsLow[u] <= dfsNum[u]
    for (int son : adj[parent]){
        // vertices nao descobertos tem tempo de descoberto (dfsNum) 0
        if (dfsDisc[son] == 0){ // se nao foi descoberto...
            dfsParent[son] = parent; // pai de v e' u (v foi descoberto por u)
            if (parent == dfsRoot)   // caso especial... precisamos contar quantas vezes descobrimos vertices a partir da raiz para descobrir se raiz e' articulacao...
                rootChildren++;

            tarjan(son, adj, dfsParent, dfsDisc, dfsLow, isArticulation, bridges, dfsCount, rootChildren, dfsRoot);

            if (dfsLow[son] >= dfsDisc[parent]) // apos visitar v recursivamente, conseguimos chegar em um vertice em v ou antes passando por u? (sem voltar pela aresta v,u)
                isArticulation[parent] = true; // store this information first
            if (dfsLow[son] > dfsDisc[parent]){ // ponte?
                bridges.push_back(make_pair(parent, son));
                // cout << u << v << endl;
            }
            dfsLow[parent] = min(dfsLow[parent], dfsLow[son]); // update dfsLow[u]
        }
        else if (son != dfsParent[parent])                     // cheguei de volta em um vertice ja descoberto... se nao passei pela aresta v,u de volta --> ciclo...
            dfsLow[parent] = min(dfsLow[parent], dfsDisc[son]); // atualize dfsLow...
    }
}

void tarjan(const vector<vector<int>> &adj,
            vector<bool> &isArticulation, vector<pair<int, int>> &bridges){
    int nv = adj.size();
    isArticulation = vector<bool>(nv, false);
    bridges.resize(0);

    vector<int> dfsParent(nv, -1);
    vector<int> dfsLow(nv, 0);
    vector<int> dfsNum(nv, 0);
    int dfsCount = 0;

    // para multiplos CCs ...th
    for (int i = 0; i < nv; i++){
        if (dfsNum[i] == 0){
            int rootChildren = 0; // resete para cada CC!!
            tarjan(i, adj, dfsParent, dfsNum, dfsLow, isArticulation, bridges, dfsCount, rootChildren, i);
            isArticulation[i] = rootChildren > 1;
        }
    }
}

int main(){

    return 0;
}