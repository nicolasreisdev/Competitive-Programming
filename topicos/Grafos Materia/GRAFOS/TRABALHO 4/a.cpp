/*
README
Aluno: Nicolas Eliel dos Reis Silva - Matrícula: 112703
Fontes de consulta: nenhuma.
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
 

typedef pair<int,int>p;
typedef long long ll;
const int MAX = 0x3f3f3f3f;
const ll LMAX = 0x3f3f3f3f3f3f3f3f;


vector<int> bfs(vector<vector<int>> &g, int v){
    queue<int> q;
    vector<int> dist(g.size(), -1);
    q.push(v);
    dist[v] = 0;
    while (!q.empty()){
        int adj = q.front();
        q.pop();

        for (auto e : g[adj]){
            if (dist[e] == -1){
                dist[e] = dist[adj] + 1;
                q.push(e);
            }
        }
    }
    // for(int i = 0; i < dist.size();i++){
    //     cout << dist[i] << " ";
    // }
    // cout << endl;
    return dist;
}



int main(){
    fastio;


    int t, cont; cin >> t;
    cont = 1;
    while(t--){
        int n, r; cin >> n >> r;
        vector<vector<int>> g(n);
        for(int i = 0; i < r; i++){
            int x, y; cin >> x >> y;
            g[x].pb(y);
            g[y].pb(x);
        }
        int x, y; cin >> x >> y;
        vector<int> ida = bfs(g, x); // calcula os minutos em relação aos outros predios 
        vector<int> volta = bfs(g, y); // calcula os minutos em relação aos outros predios 
        int ans = 0;
        for(int i = 0; i < n;i++){
            if(ida[i] + volta[i] > ans)
                ans = ida[i] + volta[i];
            
        }
        cout << "Case " << cont << ": " << ans << endl; 
        cont++;
    }
    
    return 0;
}