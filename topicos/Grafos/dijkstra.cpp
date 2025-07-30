#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define rm pop_back
#define f first
#define s second

typedef pair<int, int> p;
typedef long long ll;
const int MAX = 1e5 + 10;


vector<vector<p>>g; // peso e vertice

vector<int> dijkstra(int x){
    vector<int> distancia(g.size(), MAX);
    vector<bool> visitado(g.size(), false);

    distancia[x] = 0;

    priority_queue<p, vector<p>, greater<p>> pq; // priority queue para pegar o vertice com menor distancia
    pq.push({distancia[x], x}); // coloca o vertice inicial na fila de prioridade

    while (!pq.empty()){
        auto[peso, atual] = pq.top(); // pega o vertice com menor distancia da fila
        pq.pop(); // remove o vertice da fila

        if (!visitado[atual]) continue; // se o vertice ja foi visitado, continua
        visitado[atual] = true; // marca como visitado

        for (int i = 0; i < g[atual].size(); i++){// percorre os vizinhos do vertice atual
            auto [dist, v] = g[atual][i]; // dist = distancia do atual até o vizinho, v = vizinho

            if (distancia[atual] + dist < distancia[v]){// se a distancia do atual + a distancia do vizinho for menor que a distãncia do vizinho até então, atualiza
                distancia[v] = distancia[atual] + dist; // atualiza a distancia
                pq.push({distancia[v], v}); // coloca o vertice na fila
            }
        }
    }

    return distancia; // retorna o vetor de distancia
}


vector<int> dijkstra(int x){
    vector<int> distancia(g.size(), MAX);
    vector<bool> visitado(g.size(), false);

    distancia[x] = 0;

    while(true){
        int atual = -1;
        int peso = MAX;
        for(int i = 0; i < distancia.size();i++){ // for para pegar o vertice com menor distancia
            if(!visitado[i] && distancia[i] < peso){ // se nao foi visitado e a distancia é menor que o peso atual, atualiza
                atual = i; // atualiza o vertice atual
                peso = distancia[i];  // atualiza o peso
            }
        }

        if(atual == -1) break; // se nao tiver mais vertices para visitar, sai do loop
        visitado[atual] = true; // marca como visitado

        for(int i = 0; i< g[atual].size();i++){ // percorre os vizinhos do vertice atual
            auto[dist,v] = g[atual][i]; // dist = distancia do atual até o vizinho, v = vizinho

            if(distancia[atual] + dist < distancia[v]){ // se a distancia do atual + a distancia do vizinho for menor que a distãncia do vizinho até então, atualiza
                distancia[v] = distancia[atual] + dist; // atualiza a distancia
            }
        }
    }

    return distancia; // retorna o vetor de distancia
}



vector<p> adj[MAX];
int dijkstra(int si, int t, int n, int dist[]){
    for(int i = 0; i < n; i++) dist[i] = 1e9;
    set<p> q;
    dist[si] = 0;
    q.insert({0, si});
    while(!q.empty()){
        int u = q.begin()->s;
        q.erase(q.begin());
        for(auto x : adj[u]){
            int v = x.f, w = x.s;
            if(dist[v] > dist[u] + w){
                q.erase({dist[v], v});
                dist[v] = dist[u] + w;
                q.insert({dist[v], v});
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    



    return 0;
}