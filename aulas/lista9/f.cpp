#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define endl '\n'
#define pb push_back
#define rm pop_back
#define f first
//#define s second
#define sz size
#define in insert

typedef pair<int, int> p;
typedef long long ll;
const int MAX = 0x3f3f3f3f;
const ll LMAX = 0x3f3f3f3f3f3f3f3f;

ll fordFulkerSon(vector<vector<ll>> &g, int s, int d){
    vector<vector<ll>> r = g; // grafo residual
    int pai[g.sz()];           // vetor de pais
    memset(pai, -1, sizeof pai);
    ll fluxoMax = 0;
    while (true){
        int dist[g.sz()]; // vetor de distancias
        memset(dist, MAX, sizeof(dist));
        dist[s] = 0;
        queue<int> q;
        q.push(s);
        while (!q.empty()){ // bfs
            int u = q.front();
            q.pop();
            for (int v = 0; v < g.sz(); v++){ // para cada vizinho
                if (r[u][v] > 0 && dist[v] == MAX){ // se tem capacidade e ainda nao foi visitado
                    //cout << "de " << u << " para " << v << ": " << r[u][v] << endl;
                    dist[v] = dist[u] + 1;
                    q.push(v);
                    pai[v] = u;
                }
            }
        }
        //cout << "dist: " << dist[d] << endl;
        if (dist[d] == MAX)break;       // caso nao tenha caminho
        ll fluxo = MAX; // fluxo inicial
        for (int v = d; v != s; v = pai[v]){                                     // percorre do alvo até a origem
            fluxo = min(fluxo, r[pai[v]][v]); // minimo(fluxo , capacidade)
        }
        // cout << "fluxo: " << fluxo << endl;
        for (int v = d; v != s; v = pai[v]){ // percorre do alvo até a origem
            r[pai[v]][v] -= fluxo;
            r[v][pai[v]] += fluxo;
        }
        //cout << fluxo << endl;
        fluxoMax += fluxo;
    }
    return fluxoMax;
}

int main(){
    fastio;

    int m, w; cin >> m >> w;
    while(m != 0 || w != 0){
        vector<vector<ll>> g((2 * (m + 2)), vector<ll>((2 * (m + 2)), 0));
        for(int i = 2; i < m;i++){
            int machine, cost; cin >> machine >> cost;
            g[machine][machine+m+1] = cost;
            g[machine+m+1][machine] = cost;
        }
        g[1][1+m+1] = MAX;
        g[1+m+1][1] = MAX;
        g[m][m+m+1] = MAX;
        g[m+m+1][m] = MAX;
        for(int i = 0; i < w;i++){
            int a, b, c; cin >> a >> b >> c;
            g[a+m+1][b] += c;
            g[b+m+1][a] += c;
        }
        ll ans = fordFulkerSon(g, 1, m);
        cout << ans << endl;
        cin >> m >> w;
    }
    return 0;
}