/*
README
Aluno: Nicolas Eliel dos Reis Silva - Matrícula: 112703
Fontes de consulta: nenhuma.
*/

#include <bits/stdc++.h>
using namespace std;

//#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
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

class UnionFind{
public:
    void createset(int n){
        parent.resize(n);
        for (int i = 0; i < n; i++){
            parent[i] = i;
        }
    }

    int find(int x){
        return parent[x] == x ? x : parent[x] = find(parent[x]); // path compression
    }

    bool same(int x, int y){
        return find(x) == find(y);
    }

    void unite(int x, int y){
        parent[find(x)] = find(y);
    }

private:
    vector<int> parent;
};

int kruskal(vector<vector<int>> &g, int n){
    UnionFind dsu;
    dsu.createset(n);
    sort(g.begin(), g.end());
    int menor = -MAX;
    for(int i = 0; i < g.size();i++){
        int w = g[i][0];
        int a = g[i][1];
        int b = g[i][2];
        if(!dsu.same(a, b)){
            dsu.unite(a, b);
            if(w > menor) menor = w;
        }
    }
    return -menor;
}

int main(){
    //fastio;

    int t, number = 1; cin >> t;
    while(t){
        int n,m;cin >> n >> m;
        vector<vector<int>> g; // first vertice b, second peso da
        for(int i = 0; i < m;i++){
            int a, b, c; cin >> a >> b >> c;
            g.pb({-c, a, b});
        }
        int ans = kruskal(g, n);
        cout << "Case #" << number << ": " << ans  << endl;
        number++;
        t--;
    }

    return 0;
}