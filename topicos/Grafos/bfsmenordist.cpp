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
bool visited[MAX]={false};
int dist[MAX];

void bfs(int v){
    queue<int> fila;
    fila.push(v); // coloca o vertice inicial na fila
    visited[v] = true; // marca como visitado

    while(!fila.empty()){ // enquanto a fila nao estiver vazia
        int si = fila.front(); // pega o vertice da frente da fila
        fila.pop();
        for(auto e: g[si]){ // percorre os vizinhos do vertice
            if(!visited[e]){ // se o vizinho nao foi visitado
                dist[e] = dist[si]+1; // atualiza a distancia
                visited[e] = true; // marca como visitado
                fila.push(e);
            }
        }
    }
}

int main(){
    int n, m;
    int x, y;
    cin >> n >> m;
    for(int i = 0; i < m;i++){
        cin >> x >> y; x--; y--;
        g[x].pb(y);
        g[y].pb(x);
    }

    bfs(0);

    return 0;
}