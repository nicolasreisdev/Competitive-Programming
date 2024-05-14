#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define rm pop_back
#define f first
#define s second

typedef pair<int, int> p;
typedef long long ll;
const int MAX = 1e5+10;

// marca quem já foi visitado
bool visitado[MAX] = {false};

// busca em profundidade a partir do vertice v
void dfs(vector<int> g[MAX], int v){
    visitado[v] = true; // marca v como visitado
    for (int i : g[v])  // visita cada adjacente não visitado
        if (!visitado[i])
            dfs(g, i);
    return;
}

int main(){
    vector<int> g[MAX]; // lista de adjacencia
    int n, m;
    int a, b;

    cin >> n >> m; // n vertices, m arestas
    for (int i = 0; i < m; i++){ // lê as arestas (ligações)
        cin >> a >> b;
        g[a].push_back(b); // a liga no b
        g[b].push_back(a); // b liga no a --> retirar esta linha se for direcionado
    }

    // Escreve a matriz de adjacência
    for (int i = 1; i <= n; i++){
        cout << i << ": ";
        for (int j = 0; j < g[i].size(); j++)
            cout << g[i][j] << " ";
        // //de forma mais simples
        // for(int j: g[i])
        //   cout << j << ' ';
        cout << endl;
    }

    // Faz uma busca a partir do 1
    dfs(g, 1);

    // Escreve os visitados a partir do 1
    for (int i = 1; i <= n; i++)
        if (visitado[i])
            cout << i << " ";
    cout << endl;

    return 0;
}

/*
//Exemplo de entrada: #vertices #arestas e lista de arestas
10 8
1 3
5 7
8 10
9 10
6 2
4 3
3 2
4 2
*/