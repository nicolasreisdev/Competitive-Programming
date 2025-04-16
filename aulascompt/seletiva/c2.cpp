#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0);
#define endl '\n'

typedef long long ll;
const int MAX = 1e6 + 10;
bool visited[MAX];
int dfs(vector<vector<int>> &g, int i){
    visited[i] = true;
    for(int j = 0; j < g[i].size();j++){
        if(visited[g[i][j]]){
            return g[i][j];
        } else{
            int result = dfs(g, g[i][j]);
            return result;
        }
    }
    return i;
}


int main(){
    fastio;
    int n; cin >> n;
    vector<vector<int>> g(n);
    for(int i = 0; i < n;i++){
        int x; cin >> x;
        g[i].push_back(x-1);
    }
    vector<int> ans;
    for(int i = 0; i < n;i++){
        memset(visited, false, sizeof(visited));
        int result = dfs(g, i);
        ans.push_back(result);
    }

    for(auto e: ans) cout << e+1 << " ";
    cout << endl;

    return 0;
}