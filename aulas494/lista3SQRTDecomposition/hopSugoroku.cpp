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

int main(){
    fastio;
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++){
        cin >> v[i];
    }
    vector<ll> dp(n, 1);
    ll maxElem = *max_element(v.begin(), v.end());

    if (maxElem < sqrt(n)){
        vector<vector<ll>> somaAnterior(1 + maxElem, vector<ll>(maxElem, 0));

        for (int i = n - 1; i >= 0; i--){
            int elem = v[i];

            ll ans = 1;

            ans = (ans + somaAnterior[elem][i % elem] % 998244353);

            for (int elem2 = 1; elem2 <= maxElem; elem2++){
                somaAnterior[elem2][i % elem2] += ans;
                somaAnterior[elem2][i % elem2] %= 998244353;
            }
            dp[i] = ans;
        }
    }
    else{

        for (int i = n - 1; i >= 0; i--){
            int elem = v[i];

            ll ans = 1;

            for (int x = 1; i + x * elem < n; x++){
                ans = (ans + dp[i + x * elem]) % 998244353;
            }
            dp[i] = ans;
        }

    }

    cout << dp[0] << endl;

    return 0;
}
