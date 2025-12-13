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



void dfs(int v, vector<vector<int>> &g, int visited[]){
    for (auto u : g[v]){
        if (visited[u] == -1){
            visited[u] = abs(1 - visited[v]);
            dfs(u, g, visited);
        }
        else if (visited[u] == visited[v]){
            cout << "Impossible" << endl;
            exit(0);
        }
    }
}

int main(){
    fastio;

    int n, m;
    cin >> n >> m;
    int a[1010], b[1010],visited[1010];
    memset(visited, -1, sizeof(visited));
    vector<vector<int>> g(110);

    for (int i = 1; i <= m; i++){
        cin >> a[i] >> b[i];
        if (a[i] > b[i])swap(a[i], b[i]);
    }
    for (int i = 1; i <= m; i++){
        for (int j = 1; j <= m; j++){
            if (i != j){
                if (a[i] < a[j] && a[j] < b[i] && b[i] < b[j]){
                    g[i].pb(j);
                    g[j].pb(i);
                }
            }
        }
    }
    for (int i = 1; i <= m; i++){
        if (visited[i] == -1){
            visited[i] = 0;
            dfs(i, g, visited);
        }
    }
    for (int i = 1; i <= m; i++){
        if (visited[i] == 0)cout << "i";
        else cout << "o";
    }
    cout << endl;

    return 0;
}