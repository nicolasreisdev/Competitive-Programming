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


void dfsMelhor(int u, int parent, int edges, BIT<ll> &bit, vector<int> &cleaning){
    if(edges > k2) return;
    
    cleaning.pb(edges);

    for (auto &v: g[u]){
        if (v != parent && !roots[v]){
            dfsMelhor(v, u,  edges + 1, bit, cleaning);
        }
    }
}

int subTree(int u, int parent){
    sub[u] = 1;

    for (auto &v: g[u])
        if (v != parent && !roots[v])
            sub[u] += subTree(v, u);

    return sub[u];
}

int centroid(int u, int parent, int size){

    for (auto &v: g[u])
        if (v != parent && sub[v] > size / 2 && !roots[v])
            return centroid(v, u, size);

    return u;
}

void algorithm(int root, BIT<ll> &bit){

    int n = subTree(root, -1);
    int newRoot = centroid(root, -1, n);
    // cout << "centroid: " << newRoot << endl;

    vector<int> cleaning;
    bit.add(0, 1);
    cleaning.pb(0);


    for (auto &v: g[newRoot]){
        if (!roots[v]){
            vector<int> paths;

            dfsMelhor(v, newRoot, 1, bit, paths);

            for (auto &edges: paths){
                int l = k1 - edges;
                int r = k2 - edges;
                if (r >= 0){
                    // cout << "l ->" << l << " r -> " << r << " sum: " << bit.pref_sum(r) - bit.pref_sum(l - 1) << endl;
                    ans += bit.pref_sum(r) - bit.pref_sum(l - 1);
                }
            }

            for(auto &edges: paths){
                bit.add(edges, 1);
                cleaning.pb(edges);
            }
        }
    }

    for(auto &e: cleaning) bit.add(e, -1);

    roots[newRoot] = true;

    for (auto &v: g[newRoot]){
        if (!roots[v]){
            algorithm(v, bit);
        }
    }
}

int main(){
    fastio;
    cin >> n >> k1 >> k2;

    g.assign(n+1, vector<int>());
    sub.resize(n+1);
    roots.assign(n+1, false);
    BIT<ll> bit(n + 1);

    for (int i = 0; i < n - 1; i++){
        int u, v;
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }

    algorithm(1, bit);

    cout << ans << endl;

    return 0;
}