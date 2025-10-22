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
// #define s second
#define sz size
#define in insert

typedef pair<int, int> p;
typedef long long ll;
const int MAX = 0x3f3f3f3f;
const ll LMAX = 0x3f3f3f3f3f3f3f3f;

vector<ll> subconjuntos(const vector<int> &v){
    vector<ll> ans;
    int n = v.size();
    for (int b = 0; b < (1 << n); b++){ // gera mascaras de subconjuntos
        ll s = 0;
        for (int i = 0; i < n; i++)
            if (b & (1 << i))
                s += v[i]; // bit i ligado?
        ans.push_back(s);
    }
    sort(ans.begin(), ans.end());
    return ans;
}

int main(){
    fastio;

    int n, m;
    cin >> n >> m;
    vector<int> v(n);

    for (int i = 0; i < n; i++)
        cin >> v[i];

    vector<int> v1(v.begin(), v.begin() + n / 2);
    vector<int> v2(v.begin() + n / 2, v.end());

    vector<ll> sub1 = subconjuntos(v1);
    vector<ll> sub2 = subconjuntos(v2);

    ll ans = 0;
    for (long long a : sub1){
        auto &&[it1, it2] = equal_range(sub2.begin(), sub2.end(), m - a);
        ans += it2 - it1;
    }
    cout << ans << endl;

    return 0;
}