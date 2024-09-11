#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define endl '\n'
#define pb push_back
#define rm pop_back
#define f first
// #define s second
#define sz size
#define in insert

typedef pair<int, int> p;
typedef long long ll;
const int MAX = 0x3f3f3f3f;
const ll LMAX = 0x3f3f3f3f3f3f3f3f;


int fordFulkerSon(vector<vector<int>> &g, int s, int d){
    vector<vector<int>> r = g; // grafo residual
    int pai[g.sz()];           // vetor de pais
    memset(pai, -1, sizeof pai);
    int fluxoMaximo = 0;
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
                    //cout << "de " << u << " para " << v << " = " << r[u][v] << endl;
                    dist[v] = dist[u] + 1;
                    q.push(v);
                    pai[v] = u;
                }
            }
        }
        if (dist[d] == MAX)break;       // caso nao tenha caminho
        int fluxo = MAX; // fluxo inicial
        for (int v = d; v != s; v = pai[v]){   // percorre do alvo até a origem
            fluxo = min(fluxo, r[pai[v]][v]); // minimo(fluxo , capacidade)
        }
        // cout << "fluxo: " << fluxo << endl;
        for (int v = d; v != s; v = pai[v]){ // percorre do alvo até a origem
            r[pai[v]][v] -= fluxo;
            r[v][pai[v]] += fluxo;
        }
        //cout << fluxo << endl;
        fluxoMaximo += fluxo;
    }
    return fluxoMaximo;
}

int main(){
    fastio;
    int n;
    while (cin >> n){
        vector<int> regulator(n+1);
        vector<vector<int>> g((2*(n + 2)), vector<int>((2*(n + 2)), -1));
        for (int i = 1; i <= n; i++){
            int a;cin >> a;
            regulator[i] = a;
            g[i][i+n+2] = a;
            g[n+i+2][i] = a;
        }
        int m;
        cin >> m;
        for (int i = 0; i < m; i++){
            int a, b, c;
            cin >> a >> b >> c;
            if (g[a+n+2][b] != -1){
                g[a+n+2][b] += c;
                continue;
            }
            g[a+n+2][b] = c;
            g[b+n+2][a] = 0;
        }
        int b, d;
        cin >> b >> d;
        for (int i = 0; i < b; i++){
            int a;
            cin >> a;
            g[0][a] = regulator[a];
            g[a+n+2][0] = regulator[a];
        }
        for (int i = 0; i < d; i++){
            int a;
            cin >> a;
            g[a+n+2][n+1] = regulator[a];
            g[n+1+n+2][a] = regulator[a];
        }
        int ans = fordFulkerSon(g, 0, n + 1);
        cout << ans << endl;
    }

    return 0;
}