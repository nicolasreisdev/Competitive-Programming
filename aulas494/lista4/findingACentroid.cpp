#include <bits/stdc++.h>
using namespace std;

// calcula o tamanho da subarvore
int dfs(vector<vector<int>> &adj, vector<int> &subtreeSz, int v, int pai){
    subtreeSz[v] = 1;

    for(auto u: adj[v]){
        if(u != pai){
            subtreeSz[v] += dfs(adj, subtreeSz, u, v);
        }
    }

    return subtreeSz[v];
}

// percorre todos os vertices  e retorna o centroide...
int findCentroid(vector<vector<int>> &adj, vector<int> &subtreeSz, int v, int pai){
    for(auto u: adj[v]){
        if (u != pai && subtreeSz[u] > (adj.size() / 2)){
            return findCentroid(adj, subtreeSz, u, v);
        }
    }
    return v;
}

int main(){
    int n;
    cin >> n;
    vector<vector<int>> adj(n);
    for (int i = 0; i < n - 1; i++){
        int a, b;
        cin >> a >> b;
        a--;b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vector<int> subtreeSz(n);
    dfs(adj, subtreeSz, 0, -1);
    cout << findCentroid(adj, subtreeSz, 0, -1) + 1 << endl;
}