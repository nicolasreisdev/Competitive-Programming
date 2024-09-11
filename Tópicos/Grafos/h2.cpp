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


void dijkstra(vector<vector<p>> &g, int init, map<string, int> &names, int size){
    vector<int> dist(size + 1);
    bool visited[size];
    memset(visited, false, sizeof(visited));
    priority_queue<p, vector<p>, greater<p>> pq; // peso e vertice, minHeap
    dist[init] = 0;
    pq.push({0, init});
    ll ans = 0;
    while (!pq.empty()){
        pair<int, int> aux = pq.top();
        int peso = aux.f;
        int atual = aux.second;
        pq.pop();

        // cout << peso << " " << atual << endl;
        if (visited[atual]) continue;
        visited[atual] = true;
        // cout << "entrou" << endl;
        ans += peso; // soma o valor de todos bilhetes até o momento

        for (int i = 0; i < g[atual].size(); i++){
            int v = g[atual][i].f;
            int d = g[atual][i].second;
            dist[v] = d; // atualiza a distancia
            pq.push({d, v});
        }
    }

    for (int i = 0; i < size; i++){
        if (!visited[i]){ // caso ele não consiga visitar alguma estaçao
            cout << "Impossible" << endl;
            return;
        }
    }

    cout << ans << endl;
}

int main(){
    fastio;

    int s, c;
    cin >> s >> c;
    while (true){
        if(s == 0 && c == 0) break;
        bool flag = false;
        if (c == 0){
            flag = true;
        }
        vector<vector<p>> g(s + 1);
        map<string, int> names;
        for (int i = 0; i < s; i++){
            string x;
            cin >> x;
            names[x] = i;
        }
        for (int i = 0; i < c; i++){
            string x, y;
            cin >> x >> y;
            int dist;
            cin >> dist;
            g[names[x]].pb({names[y], dist});
            g[names[y]].pb({names[x], dist});
        }
        string init;
        cin >> init;
        if (flag) cout << 0 << endl;
        else dijkstra(g, names[init], names, s);
        cin >> s >> c;
    }

    return 0;
}