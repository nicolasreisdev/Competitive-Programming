#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define rm pop_back
#define f first
#define s second

typedef pair<int, int> p;
typedef long long ll;
const int MAX = 1e5+10;

bool visited[MAX] = {false};
vector<int>g[MAX];

void dfs(int v){
    visited[v] = true;
    for(auto w: g[v]){
        if(!visited[w]){
            dfs(w);
        }
    }
}

int main(){
    int n, m, x, y, times = 0; 
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        cin >> x >> y;
        g[x].pb(y);
        g[y].pb(x);
    }
    for(int i = 1; i <= n;i++){
        if(!visited[i]){//varredura sobre todos os 'amigos'.
            dfs(i);
            times++;//a cada grupo estabelecido é somado mais um time.
        }
    }
    cout << times << endl;

    return 0;
}