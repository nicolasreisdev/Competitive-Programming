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
const int MAX = 0x3f3f3f3f;
const ll LMAX = 0x3f3f3f3f3f3f3f3f;

void makeBipartite(vector<vector<int>> &v, int pos, vector<int> &color, int n){
    queue<int> q;
    q.push(pos);
    color[pos] = 1;
    ll white = 0, black = 1;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(auto e: v[u]){ // percorre os vizinhos de u
            if(color[e] == -1){ // se o vizinho não foi visitado
                color[e] = abs(1 - color[u]); // colore o vizinho com a cor oposta a de u
                if(color[e] == 1) black++;
                else white++;
                q.push(e); // adiciona o vizinho na fila
            }
        }
    }
    cout << white*black - (n-1)  << endl; // total de arestas - arestas internas
}




int main(){
    fastio;

    int n; cin >> n;
    vector<vector<int>> g(n+1);
    vector<int> color(n+1, -1);
    for(int i = 0; i < n-1;i++){
        int u, v; cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    makeBipartite(g, 1, color, n);
    return 0;
}