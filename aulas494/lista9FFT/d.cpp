#include <bits/stdc++.h>
using namespace std;

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define endl '\n'
#define pb push_back
#define rm pop_back
// #define f first
// #define s second
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
typedef complex<double> C;
typedef vector<double> vd;
void fft(vector<C> &a)
{
    int n = sz(a), L = 31 - __builtin_clz(n);
    static vector<complex<long double>> R(2, 1);
    static vector<C> rt(2, 1); // (^ 10% faster if double)
    for (static int k = 2; k < n; k *= 2)
    {
        R.resize(n);
        rt.resize(n);
        auto x = polar(1.0L, acos(-1.0L) / k);
        rep(i, k, 2 * k) rt[i] = R[i] = i & 1 ? R[i / 2] * x : R[i / 2];
    }
    vector<int> rev(n);
    rep(i, 0, n) rev[i] = (rev[i / 2] | (i & 1) << L) / 2;
    rep(i, 0, n) if (i < rev[i]) swap(a[i], a[rev[i]]);
    for (int k = 1; k < n; k *= 2)
        for (int i = 0; i < n; i += 2 * k)
            rep(j, 0, k)
            {
                // C z = rt[j+k] * a[i+j+k]; // (25% faster if hand-rolled)  /// include-line
                auto x = (double *)&rt[j + k], y = (double *)&a[i + j + k]; /// exclude-line
                C z(x[0] * y[0] - x[1] * y[1], x[0] * y[1] + x[1] * y[0]);  /// exclude-line
                a[i + j + k] = a[i + j] - z;
                a[i + j] += z;
            }
}
vd conv(const vd &a, const vd &b)
{
    if (a.empty() || b.empty())
        return {};
    vd res(sz(a) + sz(b) - 1);
    int L = 32 - __builtin_clz(sz(res)), n = 1 << L;
    vector<C> in(n), out(n);
    copy(all(a), begin(in));
    rep(i, 0, sz(b)) in[i].imag(b[i]);
    fft(in);
    trav(x, in) x *= x;
    rep(i, 0, n) out[i] = in[-i & (n - 1)] - conj(in[i]);
    fft(out);
    rep(i, 0, sz(res)) res[i] = imag(out[i]) / (4 * n);
    return res;
}

int main()
{
    fastio;

    string s; cin >> s;


    vector<double> a(s.size());
    vector<double> b(s.size());
    vector<double> c(s.size());

    for(int i = 0; i < s.size();i++){
        if(s[i] == 'a') a[i]++;
        if(s[i] == 'b') b[i]++;
        if(s[i] == 'c') c[i]++;   
    }

    vector<double> aReverse(a.begin(), a.end());
    vector<double> bReverse(b.begin(), b.end());
    vector<double> cReverse(c.begin(), c.end());

    reverse(aReverse.begin(), aReverse.end());
    reverse(bReverse.begin(), bReverse.end());
    reverse(cReverse.begin(), cReverse.end());

    vector<double> polyA = conv(a, aReverse);
    vector<double> polyB = conv(b, bReverse);
    vector<double> polyC = conv(c, cReverse);

    ll ans = -1;
    vector<int> ansIdx;

    for(int i = 1; i <= s.size();i++){
        int idx = (s.size() - 1) + i;

        if (ans < (ll)(polyA[idx] + polyB[idx] + polyC[idx])){
            ans = max(ans, (ll)(polyA[idx] + polyB[idx] + polyC[idx]));
            ansIdx.clear();
            ansIdx.pb(i);
        }
        else if (ans == (ll)(polyA[idx] + polyB[idx] + polyC[idx])) ansIdx.pb(i);
    }

    cout << ans << endl;

    for(int &i: ansIdx) cout << i << endl;


    return 0;
}