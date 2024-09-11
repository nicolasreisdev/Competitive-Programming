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

void makeBipartite(vector<vector<int>> &v, int pos, int color[]){
    queue<int> q;
    q.push(pos);
    color[pos] = 1;
    ll white = 0, black = 1;
    while (!q.empty()){
        int u = q.front();
        q.pop();
        for (auto e : v[u]){ // percorre os vizinhos de u
            if (color[e] == -1){ // se o vizinho não foi visitado
                color[e] = abs(1 - color[u]); // colore o vizinho com a cor oposta a de u
                if (color[e] == 1) black++;
                else white++;
                q.push(e); // adiciona o vizinho na fila
            }
        }
    }
    //cout << "white: " << white << " black: " << black << endl;
    cout << min(white, black) << endl;
}

int main(){
    fastio;
    int t, caso = 1; cin >> t;
    while(t){
        int n, m; cin >> n >> m;
        vector<vector<int>> g(n+1);
        int color[n+1];
        memset(color, -1, sizeof(color));
        for(int i = 1; i <= m; i++){
            int a, b; cin >> a >> b;
            //cout << "a: " << a << " b: " << b << endl;
            g[a].pb(b);
            g[b].pb(a);
        }
        cout << "Case " << caso << ": ";
        makeBipartite(g, 1, color);
        caso++;
        //string salto; cin >> salto;
        t--;
    }
    return 0;
}