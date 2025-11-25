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

int main(){
    fastio;

    int n; cin >> n;
    vector<double> v(n), f(100010);
    int zero = 0;
    for(int i = 0; i < n;i++) {
        int x; cin >> x;
        v[i] = x;
        if(x == 0) zero++;
        f[50000 + x]++;
    }

    vector<double> soma = conv(f, f);

    ll ans = 0;
    for(int i = 0;i < n;i++){
        ll idx = v[i] + 2*50000;
        if((int)v[i] % 2 == 0){
            ll rem = v[i] / 2 + 50000;
            ans -= (ll)round(f[rem]);
        }
        ans += (ll)round(soma[idx]);
        if(v[i] == 0 && zero > 0) ans-=2*(zero-1);
        else ans-=2*zero;
    }

    cout << ans << endl;
 


    return 0;
}