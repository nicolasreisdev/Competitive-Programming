#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
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

struct dsu{
    vector<int> parent, size;
    dsu(int n){
        parent.resize(n);                      // Vetor de pais
        size.resize(n, 1);                     // Vetor de tamanho
        iota(parent.begin(), parent.end(), 0); // Inicializa o vetor de pais
    }

    int find(int x){
        return parent[x] == x ? x : parent[x] = find(parent[x]); // Path compression
    }

    void unite(int x, int y){
        x = find(x);
        y = find(y);
        if (x != y){
            if (size[x] < size[y])
                swap(x, y); // por tamanho
            parent[y] = x;
            size[x] += size[y];
        }
    }

    bool same(int x, int y){
        return find(x) == find(y);
    }

    int get_size(int x){
        return size[find(x)];
    }
};

//vector<tuple<int, int, int>> edges; // {weight, from, to}

map<string, ll> names;
void kruskal(vector<vector<ll>> &g, int n, ll init){
    dsu dsu(n);                       // Inicializa a DSU
    ll cost = 0;                      // Custo total da MST
    sort(g.begin(), g.end());
    for(auto edges: g){
        ll w = edges[0];
        ll x = edges[1];
        ll y = edges[2];
        if(!dsu.same(x, y)){ // Se nao forma ciclo (x e y nao estao na mesma componente), isso serve para percorrermos todas as arestas e nao formar ciclos
            dsu.unite(x, y);
            cost += w;
            string l, r;
            cout << "adicionando a aresta " << w << " de " << x << " para " << y << endl;
        }
    }   

    for(int i = 0; i < n;i++){
        if(!dsu.same(i, init))
        { // se algum vertice nao esta conectado ao vertice inicial
            cout << "Impossible" << endl;
            return;
        }
    }

    cout << cost << endl;
    return;
}

int main(){
    fastio;

    int s, c;
    cin >> s >> c;
    while (s != 0 || c != 0){
        //bool flag = false;
        /*if(c == 0){
            flag = true;
        }*/
        vector<vector<ll>> g;
        for(int i = 0; i < s;i++){
            string x; cin >> x;
            names[x] = i;
            cout << x << " = " << i << endl;
        }
        for(int i = 0; i < c;i++){
            string x, y; cin >> x >> y;
            ll dist; cin >> dist;
            g.pb({dist, names[x], names[y]});
        }
        string init; cin >> init;
        //if(flag) cout << 0 << endl;
        /*else{
            kruskal(g, s, names[init]);
        }*/
        kruskal(g, s, names[init]);
        cin >> s >> c;
    }

    return 0;
}