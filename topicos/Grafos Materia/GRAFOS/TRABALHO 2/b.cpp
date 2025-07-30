/*
README
Aluno: Nicolas Eliel dos Reis Silva - Matrícula: 112703
Fontes de consulta: nenhuma
*/

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


void bfs(vector<vector<int>> &g, int v){
    queue<int> q;
    vector<int> dist(g.size(), -1);
    q.push(v);
    dist[v] = 0;
    while(!q.empty()){
        int adj = q.front();
        q.pop();

        for(auto e: g[adj]){
            if(dist[e] == -1){
                dist[e] = dist[adj]+1;
                q.push(e);
            }
        }
    }

    for (int i = 1; i < g.size();i++){
        cout << i << " " << dist[i] << endl;
    }
}


int main()  {
    fastio;

    int n; cin >> n;
    vector<vector<int>> g(n+1);
    for (int i = 1; i <= n;i++){
        int v, a; cin >> v >> a;
        for(int j = 0; j < a; j++){
            int vadj; cin >> vadj;
            g[v].pb(vadj);
        }
    }

    bfs(g, 1);


    return 0;
}