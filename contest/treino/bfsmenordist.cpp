#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define rm pop_back
#define f first
#define s second

typedef pair<int, int> p;
typedef long long ll;
const int MAX = 1e5 + 10;

vector<int>g[MAX];
bool visited[MAX]={false};
int dist[MAX];

void bfs(int v){
    queue<int> fila;
    fila.push(v);
    visited[v] = true;

    while(!fila.empty()){
        int s = fila.front();
        fila.pop();
        for(auto e: g[s]){
            if(!visited[e]){
                dist[e] = dist[s]+1;
                visited[e] = true;
                fila.push(e);
            }
        }
    }
}

int main(){
    int n, m;
    int x, y;
    cin >> n >> m;
    for(int i = 0; i < m;i++){
        cin >> x >> y; x--; y--;
        g[x].pb(y);
        g[y].pb(x);
    }

    bfs(0);



    return 0;
}