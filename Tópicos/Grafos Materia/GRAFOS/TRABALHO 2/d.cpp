/*
README
Aluno: Nicolas Eliel dos Reis Silva - Matrícula: 112703
Fontes de consulta: Chat GPT para saber quando uma ordenação topológica não será válida (ciclo) e materiais de competitiva para ordenação topológica
*/

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

typedef pair<int, int> p;
typedef long long ll;
const int MAX = 2*1e5;
const ll LMAX = 0x3f3f3f3f3f3f3f3f;


void dfs(vector<vector<int>> &g, int v, stack<int> &pilha, vector<int> &visitado, bool &flag){
    visitado[v] = 1; // marca como em processo de visita
    for (int i : g[v])
        if (visitado[i] == 0) dfs(g, i, pilha, visitado, flag); // se não foi visitado, faz a busca
        else if (visitado[i] == 1) flag = true; // se foi visitado em processo de visita, tem ciclo

    pilha.push(v); // adiciona na pilha o último elemento visitado (ou seja o que não tem mais adjacente não visitado)
    visitado[v] = 2; // marca como visitado totalmente
}

void topologicalSort(vector<vector<int>> &g, int n, vector<int> &fontes, vector<int> &visitado){
    stack<int> pilha;
    bool flag = false;
    sort(fontes.begin(), fontes.end()); // ordena para pegarmos as fontes

    for (int i = 1; i < fontes.size(); i++){
        if (visitado[i] == 0) dfs(g, i, pilha, visitado, flag); // se não foi visitado, faz a busca
    }

    if(flag) cout << "IMPOSSIBLE" << endl; // se houver ciclo
    else{
        while (!pilha.empty()){ // desempilhamos a ordenação topológica
            cout << pilha.top() << " ";
            pilha.pop();
        }
        cout << endl;
    }
}

int main(){
    fastio;

    int n, m; cin >> n >> m;
    vector<vector<int>> g(n+1);
    vector<int> fontes(n+1, 0);
    vector<int> visitado(n+1, 0);
    for(int i = 0; i < m;i++){
        int a, b; cin >> a  >> b;
        g[a].pb(b);
        fontes[b]++; // incrementa o grau de entrada do vértice b
    }


    topologicalSort(g, n, fontes, visitado);


    return 0;
}