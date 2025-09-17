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

typedef long long ll;
typedef pair<ll, ll> p;

const int MAX = 1e6;
const int SQ = sqrt(MAX);
ll v[MAX];

ll ans, freq[MAX];

inline void insert(int p){
    int o = v[p];
    ans -= freq[o] * freq[o] * o;
    freq[o]++;
    ans += freq[o] * freq[o] * o;
}

inline void erase(int p){
    int o = v[p];
    ans -= freq[o] * freq[o] * o;
    freq[o]--;
    ans += freq[o] * freq[o] * o;
}

inline ll hilbert(ll x, ll y){
    static int N = 1 << (__builtin_clz(0) - __builtin_clz(MAX));
    int rx, ry, s;
    ll d = 0;
    for (s = N / 2; s > 0; s /= 2){
        rx = (x & s) > 0, ry = (y & s) > 0;
        d += s * ll(s) * ((3 * rx) ^ ry);
        if (ry == 0){
            if (rx == 1)
                x = N - 1 - x, y = N - 1 - y;
            swap(x, y);
        }
    }
    return d;
}

#define HILBERT true
vector<ll> MO(vector<pair<ll, ll>> &q){
    ans = 0;
    int m = q.size();
    vector<ll> ord(m);
    iota(ord.begin(), ord.end(), 0);
#if HILBERT
    vector<ll> h(m);
    for (int i = 0; i < m; i++)
        h[i] = hilbert(q[i].first, q[i].second);
    sort(ord.begin(), ord.end(), [&](int l, int r)
         { return h[l] < h[r]; });
#else
    sort(ord.begin(), ord.end(), [&](int l, int r)
         {
		if (q[l].first / SQ != q[r].first / SQ) return q[l].first < q[r].first;
		if ((q[l].first / SQ) % 2) return q[l].second > q[r].second;
		return q[l].second < q[r].second; });
#endif
    vector<ll> ret(m);
    int l = 0, r = -1;

    for (int i : ord){
        int ql, qr;
        tie(ql, qr) = q[i];
        while (r < qr)
            insert(++r);
        while (l > ql)
            insert(--l);
        while (l < ql)
            erase(l++);
        while (r > qr)
            erase(r--);
        ret[i] = ans;
    }
    return ret;
}

int main(){
    fastio;
    int n, t; cin >> n >> t;

    for(int i = 0; i < n;i++) cin >> v[i];


    int mo_left = -1;
    int mo_right = -1;

    vector<p> queries(t);

    for(int i = 0; i < t;i++){
        int l , r; cin >> l >> r;
        l--;r--;
        queries[i] = {l, r}; 
    }

    vector<ll> ans = MO(queries);

    for(auto resp: ans) cout << resp << endl;

    return 0;
}