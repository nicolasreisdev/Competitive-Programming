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


void dfs(int x, int prev, vector<vector<int>> &v, vector<int> &p, set<int> &ans, vector<int> &gp){
    if(p[x] != -1){
        gp[x] = gp[p[x]]+1; // atualiza a profundidade
        ans.in(gp[x]); // insere a profundidade
    }
    for(auto e: v[x]){ // para cada filho
        if(e != prev) dfs(e, x, v, p, ans, gp); // se não for o pai, chama a dfs
    }
}

int main(){
    fastio;
    int n; cin >> n;
    vector<vector<int>> v(n+1);
    vector<int> p(n+1), gp(n+1);
    set<int> ans;
    for(int i = 0; i < n;i++){
        int x; cin >> x;
        if(x != -1){ // se não for raiz
            v[i+1].pb(x);
            v[x].pb(i+1);
        }
        p[i+1] = x;
    }
    for(int i = 1; i <= n;i++) dfs(i, p[i], v, p, ans, gp);

    cout << ans.size()+1 << endl;

    return 0;
}