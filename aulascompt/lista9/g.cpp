#include <bits/stdc++.h>
using namespace std;

//#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
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


void dfs(int v, vector<vector<int>> &g, int visited[]){
    visited[v] = true;
    for (int u = 1; u < g.size(); u++){
        if (g[v][u] && !visited[u]){
            dfs(u, g, visited);
        }
    }
}

bool isConnectedFrom(vector<vector<int>> &g,int i, int n){
    int visited[n + 1];
    memset(visited, 0, sizeof(visited));
    dfs(i, g, visited);
    for (int v = 1; v <= n; v++){
        if (!visited[v]){
            return false;
        }
    }
    return true;
}

int main(){
    //fastio;

    int n, m; cin >> n >> m;
    while(n != 0 && m != 0){
        vector<vector<int>> g(n+2, vector<int>(n+2, 0));
        for(int i = 0; i < m;i++){
            int a, b, c; cin >> a >> b >> c;
            if(c == 1){
                g[a][b] = 1;
            }
            else{
                g[a][b] = 1;
                g[b][a] = 1;
            }
        }
        bool flag = false;
        for(int i = 1; i <= n;i++){
            if(!isConnectedFrom(g, i, n)){
                //cout << "entrei " << i << endl;
                flag = true;
                cout << 0 << endl;
                break;
            }
        }
        if(!flag){
            cout << 1 << endl;
        }

        cin >> n >> m;
    }

    return 0;
}