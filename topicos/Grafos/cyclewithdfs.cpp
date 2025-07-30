#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define rm pop_back
#define f first
#define s second

typedef pair<int, int> p;
typedef long long ll;
const int MAX = 1e5 + 10;

// marca quem já foi visitado
bool visitado[MAX] = {false};

// busca em profundidade a partir do vertice v
void dfsCycle(vector<int> g[MAX], int v){
    visitado[v] = true; // marca v como visitado
    for (int i : g[v]){ // visita cada adjacente não visitado
        if(visitado[i]) cout << "Ciclo encontrado" << endl;
        else if (!visitado[i]) dfsCycle(g, i);
    }
    return;
}

int main()
{
    vector<int> g[MAX]; // lista de adjacencia
    int n, m;
    int a, b;

    cin >> n >> m; // n vertices, m arestas
    for (int i = 0; i < m; i++){ // lê as arestas (ligações)
        cin >> a >> b;
        g[a].push_back(b); // a liga no b
        g[b].push_back(a); // b liga no a --> retirar esta linha se for direcionado
    }

    for(int i = 0; i < n;i++){
        for(int j = 0; j < n;j++) visitado[j] = false; // zera o vetor de visitados
        dfsCycle(g, i); // Faz uma busca a partir do i
    }

    return 0;
}
