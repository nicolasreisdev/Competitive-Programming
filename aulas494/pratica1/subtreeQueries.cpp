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

template <class T> class BIT {
  private:
	int size;
	vector<T> bit;
	vector<T> arr;

  public:
	BIT(int size) : size(size), bit(size + 1), arr(size) {}

	/** Sets the value at index ind to val. */
	void set(int ind, T val) { add(ind, val - arr[ind]); }

	/** Adds val to the element at index ind. */
	void add(int ind, T val) {
		arr[ind] += val;
		ind++;
		for (; ind <= size; ind += ind & -ind) { bit[ind] += val; }
	}

	/** @return The sum of all values in [0, ind]. */
	T pref_sum(int ind) {
		ind++;
		T total = 0;
		for (; ind > 0; ind -= ind & -ind) { total += bit[ind]; }
		return total;
	}
};

ll timer = 0;
void dfs(vector<vector<ll>> &g, int v, int parent, vector<ll> &start, vector<ll> &end){
    start[v] = timer;
    //cout << "Vértice: " << v << endl;
    timer++;
    for (ll &u: g[v]) {
        if(u != parent) dfs(g, u, v, start, end);
    }
    //cout << "Timer: " << timer << endl; 
    end[v] = timer;
}

int main(){

    ll n, q; cin >> n >> q;
    vector<vector<ll>> g(n+1);
    vector<ll> value(n+1);
    vector<ll> start(n+1);
    vector<ll> end(n+1);
    for(int i = 1; i <= n;i++){
        ll x; cin >> x;
        value[i] = x;
    }


    for(int i = 1; i < n;i++){
        int v, e; cin >> v >> e;
        g[v].push_back(e);
        g[e].push_back(v);
    }


    dfs(g, 1, 0, start, end);

    BIT<ll> bit(n+1);
    for(int i = 1; i <= n;i++){
        bit.add(start[i], value[i]);
    }

    for(int i = 0; i < q;i++){
        int query; cin >> query;
        if(query == 1){
            ll v, x;
            cin >> v >> x;
            bit.add(start[v], x-value[v]);
            value[v] = x;
        }
        else{
            ll v;
            cin >> v;
            ll sum = bit.pref_sum(end[v] - 1) - bit.pref_sum(start[v] - 1);
            cout << sum << endl;
        }
    }

    return 0;
}