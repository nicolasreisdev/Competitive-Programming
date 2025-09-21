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

template <class T>
class BIT
{
private:
    int size;
    vector<T> bit;
    vector<T> arr;

public:
    BIT(int size) : size(size), bit(size + 1), arr(size) {}

    /** Sets the value at index ind to val. */
    void set(int ind, T val) { add(ind, val - arr[ind]); }

    /** Adds val to the element at index ind. */
    void add(int ind, T val)
    {
        arr[ind] += val;
        ind++;
        for (; ind <= size; ind += ind & -ind)
        {
            bit[ind] += val;
        }
    }

    /** @return The sum of all values in [0, ind]. */
    T pref_sum(int ind)
    {
        ind++;
        T total = 0;
        for (; ind > 0; ind -= ind & -ind)
        {
            total += bit[ind];
        }
        return total;
    }
};

int n, k1, k2;
ll ans = 0;
vector<int> sub;
vector<vector<int>> g;
vector<bool> roots;

void dfsAns(int u, int parent, int edges, BIT<ll> &bit){

    int l = k1 - edges;
    int r = k2 - edges;
    if (r >= 0){
        // cout << "entrei1: u -> " << u << " l -> " << l << " r -> " << r << " soma: " <<  bit.pref_sum(r) - bit.pref_sum(l - 1) << endl;
        ans += bit.pref_sum(r) - bit.pref_sum(l - 1);
    }

    for (auto &v : g[u]){
        if (v != parent && !roots[v])
        {
            dfsAns(v, u, edges + 1, bit);
        }
    }
}

void dfsMelhor(int u, int parent, int edges, BIT<ll> &bit){
    if (edges > k2)
        return;

    bit.add(edges, 1);

    for (auto &v : g[u]){
        if (v != parent && !roots[v]){
            dfsMelhor(v, u, edges + 1, bit);
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

long long int _tam_crivo;
long long int primes[10000010];

void crivo(){
    _tam_crivo = 1000000 + 10; // tamanho do crivo 1e6 + 10
    memset(primes, 1, sizeof(primes)); // 1 = primo, 0 = composto
    vector<int> primos;
    primes[0] = 0; // 0 não é primo
    for (long long int i = 2; i <= sqrt(_tam_crivo); i++){ // para i de 2 até a raiz de _tam_crivo
        if (primes[i]){ // se i é primo
            for (long long int j = i * i; j <= _tam_crivo; j += i){ // marcar todos os múltiplos de i como compostos
                primes[j] = 0;
            }
            primos.push_back(i);
        }
    }
}


void algorithm(int root, BIT<ll> &bit){
    int n = subTree(root, -1);
    int newRoot = centroid(root, -1, n);
    // cout << "centroid: " << newRoot << endl;

    bit.add(0, 1);

    for (auto &v : g[newRoot]){
        if (!roots[v]){
            dfsAns(v, newRoot, 1, bit);
            dfsMelhor(v, newRoot, 1, bit);
        }
    }


    roots[newRoot] = true;

    for (auto &v : g[newRoot]){
        if (!roots[v])
        {
            algorithm(v, bit);
        }
    }
}

int main(){
    fastio;
    crivo();
    cin >> n;

    g.assign(n + 1, vector<int>());
    sub.resize(n + 1);
    roots.assign(n + 1, false);
    BIT<ll> bit(n + 1);

    for (int i = 0; i < n - 1; i++){
        int u, v;
        cin >> u >> v;
        g[u-1].pb(v-1);
        g[v-1].pb(u-1);
    }

    algorithm(0, bit);

    cout << ans << endl;

    return 0;
}