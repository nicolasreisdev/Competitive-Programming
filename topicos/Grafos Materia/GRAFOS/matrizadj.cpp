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


void dfs(const vector<vector<bool>> &mat, int v, vector<bool> &visitados, vector<int> &cc) {
    visitados[v] = true;
    cc.pb(v);
    for(int i = 0; i < mat.size(); i++){ // percorre todos os vértices
        if(mat[v][i] && !visitados[i]){ // se existe aresta e não foi visitado
            dfs(mat, i, visitados, cc); // visitar
        }
    }
}

void numArestas(vector<vector<bool>> &mat, int v){
    int n = mat.size();
    vector<bool> nocc(n, false);
    vector<int>cc;
    dfs(mat, v, nocc, cc);
}

int main(){
    int n, m; cin >> n >> m;
    vector<vector<bool>> adj(n, vector<bool>(n, 0));
    for(int i = 0; i < m; i++){
        int a, b; cin >> a >> b;
        adj[a][b] = 1;
        adj[b][a] = 1;
    }

    numArestas(adj, 0);


    return 0;
}