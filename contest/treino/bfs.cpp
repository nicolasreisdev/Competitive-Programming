#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define rm pop_back
#define f first
#define s second

typedef pair<int, int> p;
typedef long long ll;
const int MAX = 1e5 + 10;

vector<int> g[MAX];
vector<int>pai(MAX);
bool visited[MAX] = {false};

void bfs(int v){
    queue<int> fila;
    fila.push(v);
    visited[v] = true;

    pai[v] = v;
    while (!fila.empty()){
        int s = fila.front();
        fila.pop();
        for (auto e : g[s])
        {
            if (!visited[e]){
                visited[e] = true;
                pai[e] = s;
                fila.push(e);
            }
        }
    }
}

vector<int> path(int v){
    vector<int> ret;
    if(!visited[v]){
        return ret;
    }

    ret.pb(v);
    while(pai[v]!=v){
        v = pai[v];
        ret.pb(v);
    }
    reverse(ret.begin(), ret.end()); //muda a ordem do vector. ex: de 1,2,3,4 para 4,3,2,1. Bom para questões de string.    

    return ret;
}

int main()
{
    int n, m;
    int x, y;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> x >> y;
        x--;
        y--;
        g[x].pb(y);
        g[y].pb(x);
    }

    bfs(0);
    vector<int> ans = path(n-1);
    if(ans.size() == 0){
        cout << "IMPOSSIBLE" << endl;
    }
    else {
        cout << ans.size() << endl;
        for(auto e: ans){
            cout << e+1 << " ";
        }
        cout << endl;
    }

    return 0;
}   