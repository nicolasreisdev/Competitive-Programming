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
#define sz(x) (int)(x).size()
#define in insert

typedef pair<int, int> p;
typedef long long ll;
typedef unsigned long long ull;
const int MAX = 0x3f3f3f3f;
const ll LMAX = 0x3f3f3f3f3f3f3f3f;

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define trav(a, x) for (auto &a : x)

const ll mod = 786433, root = 10;

    typedef unsigned long long ull;
ull modmul(ull a, ull b)
{
    ll ret = a * b - mod * ull(1.L / mod * a * b);
    return ret + mod * (ret < 0) - mod * (ret >= (ll)mod);
}
ull modpow(ull b, ull e)
{
    ull ans = 1;
    for (; e; b = modmul(b, b), e /= 2)
        if (e & 1)
            ans = modmul(ans, b);
    return ans;
}

typedef vector<ll> vl;
void ntt(vl &a, vl &rt, vl &rev, int n)
{
    rep(i, 0, n) if (i < rev[i]) swap(a[i], a[rev[i]]);
    for (int k = 1; k < n; k *= 2)
        for (int i = 0; i < n; i += 2 * k)
            rep(j, 0, k)
            {
                ll z = rt[j + k] * a[i + j + k] % mod, &ai = a[i + j];
                a[i + j + k] = (z > ai ? ai - z + mod : ai - z);
                ai += (ai + z >= mod ? z - mod : z);
            }
}

vl conv(const vl &a, const vl &b)
{
    if (a.empty() || b.empty())
        return {};
    int s = sz(a) + sz(b) - 1, B = 32 - __builtin_clz(s), n = 1 << B;
    vl L(a), R(b), out(n), rt(n, 1), rev(n);
    L.resize(n), R.resize(n);
    rep(i, 0, n) rev[i] = (rev[i / 2] | (i & 1) << B) / 2;
    ll curL = mod / 2, inv = modpow(n, mod - 2);
    for (int k = 2; k < n; k *= 2)
    {
        ll z[] = {1, modpow(root, curL /= 2)};
        rep(i, k, 2 * k) rt[i] = rt[i / 2] * z[i & 1] % mod;
    }
    ntt(L, rt, rev, n);
    ntt(R, rt, rev, n);
    rep(i, 0, n) out[-i & (n - 1)] = L[i] * R[i] % mod * inv % mod;
    ntt(out, rt, rev, n);
    return {out.begin(), out.begin() + s};
}

struct forSize
{
    bool operator()(const vl &a, const vl &b)
    {
        return sz(a) > sz(b); 
    }
};

int main()
{
    fastio;

    int m;
    cin >> m;
    priority_queue<vl, vector<vl>, forSize> pq;
    for (int i = 0; i < m; i++){
        int x; cin >> x;
        vector<p> v(x);
        int maxVal = 0;
        for(int i = 0; i < x; i++){
            cin >> v[i].f >> v[i].s;
            maxVal = max(maxVal, v[i].f);
        }

        vl p(maxVal + 1);
        for(auto values: v){
            p[values.f] = values.s;
        }
        pq.push(p);
    }

    while (pq.size() > 1)
    {
        vl a = pq.top();
        pq.pop();
        vl b = pq.top();
        pq.pop();
        pq.push(conv(a, b));
    }

    vl ans = pq.top();
    
    for(int i = 0; i < ans.size();i++){
        if(ans[i] > 0) cout << i << " " << ans[i] << endl;
    }

    return 0;
}