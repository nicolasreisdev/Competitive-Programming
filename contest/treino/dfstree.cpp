#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define rm pop_back
#define f first
#define s second

typedef pair<int, int> p;
typedef long long ll;
const int MAX = 1e5 + 10;
vector<int>g[MAX];
int dist[MAX];
// ALGORITMO DE MAIOR DISTÃNCIA EM UMA ÁRVORE

void dfs(int v){
    for(auto e: g[v]){
        if(dist[e] == -1){//se a distãncia for igual a '-1', ou seja, inicial não visitada.
            dist[e] = dist[v]+1;//a distãncia desse elemento é a última interação +1. A cada aresta é somado a distãncia de 1 
            dfs(e);//é inicializado uma nova busca.
        }
    }
}

int main(){
    int n; cin >> n;
    int x, y;
    int distmax = -1, posmax = -1;

    for(int i = 0; i < n-1;i++){//a quantidade de arestas é igual à (vértices-1)
        cin >> x >> y;
        x--; //subtraido pois o grafo é inicializado a partir do 1, mas queremos a posição 0.
        y--;
        g[x].pb(y);
        g[y].pb(x);
    }
    memset(dist, -1, sizeof dist);//função memset classifica todos os elementos do array com um inteiro com complexidade de O(N).
    dist[0] = 0;//a distãncia é inicializada com 0 a partir do vétice 'pai'.
    dfs(0);//inicialização da busca do 'pai' inicial.

    //VERIFICAÇÃO DA POSIÇÃO DE MAIOR DISTÃNCIA
    for(int i = 0; i < n;i++){
        if(dist[i] > distmax){
            distmax = dist[i];
            posmax = i;
        }
    }

    //REINICIALIZAÇÃO PARA ACHAR O VÉRTICE MAIS DISTANTE DELE
    memset(dist, -1, sizeof dist); // reinicialização das distâncias.
    dist[posmax] = 0;//a busca é inicializada a partir do vértice mais distante, para encontrar vértice mais distante dele.
    dfs(posmax);

    //VERIFICAR QUAL O VÉRTICE MAIS DISTANTE DELE
    int diametro;
    for(int i = 0;i < n;i++){
        diametro = max(diametro, dist[i]);//o diametro será o maior valor encontrado no vetor de distâncias.
    }
    cout << diametro << endl;

    return 0;
}