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

int fordFulkerSon(vector<vector<int>> &g, int s, int d, vector<int> &regulator){
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
                if(v == 5) cout << "de " << u << " para " << v << " " << r[u][v] << endl;
                if (r[u][v] > 0 && dist[v] == MAX){ // se tem capacidade e ainda nao foi visitado
                    //cout << "de " << u << " para " << v << " " << r[u][v] << endl;
                    //cout << regulator[v-1] << endl;
                    dist[v] = regulator[v - 1];
                    // cout << "dist " << v << " " << dist[v] << endl;
                    q.push(v);
                    pai[v] = u;
                }
            }
        }
        // cout << "distancia " << d << " " <<  dist[d] << endl;
        if (dist[d] == MAX)break;
        int fluxo = MAX; // fluxo inicial
        for (int v = d; v != s; v = pai[v]){ // percorre do alvo até a origem
            //cout << pai[v] << " " << v <<  " " << r[pai[v]][v] << " regulator: " << regulator[v-1] << endl;
            if(v == 1) fluxo = min(fluxo, r[pai[v]][v]);
            else fluxo = min(fluxo, min(regulator[v-1],r[pai[v]][v])); // minimo(fluxo , capacidade)
        }
        // cout << "fluxo: " << fluxo << endl;
        for (int v = d; v != s; v = pai[v]){ // percorre do alvo até a origem
            swap(r[pai[v]][v], r[v][pai[v]]); // atualiza o grafo residual (invertendo a aresta)
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
        for (int i = 1; i <= n; i++){
            cin >> regulator[i];
            //cout << regulator[i] << endl;
        }
        int m;
        cin >> m;
        vector<vector<int>> g(n + 2, vector<int>(n + 2, -1)); // g[0] = barisal , g[n+1] = dhaka
        for (int i = 0; i < m; i++){
            int a, b, c;
            cin >> a >> b >> c;
            //cout << a << " " << b << " " << c << endl;
            if (g[a][b] != -1){ // se ja existe uma aresta entre a e b, soma a capacidade
                cout << "ja existe" << endl;
                g[a][b] += c;
                continue;
            }
            g[a][b] = c;
            g[b][a] = 0;
        }
        int b, d;
        cin >> b >> d;
        for (int i = 0; i < b; i++)
        {
            int a;
            cin >> a;
            // cout << a << " " << regulator[a-1] << endl;
            g[0][a] = regulator[a];
            g[a][0] = regulator[a];
        }
        for (int i = 0; i < d; i++)
        {
            int a;
            cin >> a;
            // cout << a << " " << n+1 << endl;
            g[a][n + 1] = regulator[a];
            g[n + 1][a] = regulator[a];
        }
        /*
        for (int i = 0; i < n + 2; i++){
            for (int j = 0; j < n + 2; j++){
                cout << "de " << i << " para " << j << " " << g[i][j] << " " << endl;
            }
            cout << endl;
        }*/
        int ans = fordFulkerSon(g, 0, n + 1, regulator);
        cout << ans << endl;
    }

    return 0;
}