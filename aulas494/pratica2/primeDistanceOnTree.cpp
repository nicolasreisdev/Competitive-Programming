#include <bits/stdc++.h>
using namespace std;

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
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

long long int _tam_crivo;
vector<int> primos;

void crivo(int n){             
    vector<bool> primes(n+1, true);
    primes[0] = primes[1] = 0; // 0 não é primo
    for (long long int i = 2; i <= n; i++){ 
        if (primes[i])
        { // se i é primo
            for (long long int j = i * i; j <= n; j += i)
            { // marcar todos os múltiplos de i como compostos
                primes[j] = 0;
            }
            primos.push_back(i);
        }
    }
}

ll n;
ll ans = 0;
vector<int> sub;
vector<vector<int>> g;
vector<vector<int>> dist;
vector<bool> roots;

ll dfsAns(int u, int parent, int depth, int edges){
    ll localAns = 0;
    for(auto &prime: primos){
        int rest = prime - edges;
        if(rest < 0) continue; 
        if(!dist[depth][rest]) break; // primos em ordem crescente
        if(prime != edges) localAns += dist[depth][rest]; // caminho em subárvores diferentes (soma se houver caminho edges+rest == prime)
        else localAns += 2*dist[depth][rest]; // caminho na própria subárvore, prime == edges (contagem de 2*dist para não quebrar o algoritmo)
    }

    for (auto &v : g[u]){
        if (v != parent && !roots[v]){
            localAns += dfsAns(v, u, depth, edges + 1);
        }
    }
    return localAns;
}

void dfsMelhor(int u, int parent, int depth, int edges, int add){

    dist[depth][edges] += add; // +1 adiciona caminho -1 remove o caminho 

    for (auto &v : g[u]){
        if (v != parent && !roots[v]){
            dfsMelhor(v, u, depth,  edges + 1, add);
        }
    }
}

int subTree(int u, int parent){
    sub[u] = 1;

    for (auto &v : g[u])
        if (v != parent && !roots[v])
            sub[u] += subTree(v, u);

    return sub[u];
}

int centroid(int u, int parent, int size){

    for (auto &v : g[u])
        if (v != parent && sub[v] > size / 2 && !roots[v])
            return centroid(v, u, size);

    return u;
}



void algorithm(int root, int depth){
    int n = subTree(root, -1);
    int newRoot = centroid(root, -1, n);
    // cout << "centroid: " << newRoot << endl;
    
    if(dist[depth].size() < n) dist[depth].resize(n, 0);

    dfsMelhor(newRoot, newRoot, depth, 0, 1);

    ll aux = 0;
    for (auto &v : g[newRoot]){
        if (!roots[v]){
            dfsMelhor(v, newRoot, depth, 1, -1); // exclusão
            aux += dfsAns(v, newRoot, depth, 1); // consulta
            dfsMelhor(v, newRoot, depth, 1, 1); // inclusão para as próximas subárvores
        }
    }

    ans += aux/2; // correção

    
    roots[newRoot] = true;

    fill(dist[depth].begin(), dist[depth].begin() + n, 0); // limpa
    
    for (auto &v : g[newRoot]){
        if (!roots[v]){
            algorithm(v, depth+1);
        }
    }
}

int main(){
    fastio;
    cin >> n;
    crivo(n);

    g.assign(n + 1, vector<int>());
    sub.resize(n + 1);
    roots.assign(n + 1, false);
    dist.assign(n+1, vector<int>());

    for (int i = 0; i < n - 1; i++){
        int u, v;
        cin >> u >> v;
        g[u-1].pb(v-1);
        g[v-1].pb(u-1);
    }

    algorithm(0, 0);
    double combinacao = (n*(n-1))/2;

    cout << (ans/combinacao) << endl;

    return 0;
}