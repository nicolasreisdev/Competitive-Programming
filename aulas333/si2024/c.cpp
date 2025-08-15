#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
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


map<ll, ll>dp;
int cont = 0;

ll func(ll n){
    if(cont >= 200) return dp[n] = -2;
    cont++;
    if(n == 1) return 0;
    if(dp[n] == -2) return dp[n];
    if(dp[n] != 0) return dp[n];
    ll resp = 1;
    for (ll i = 2; i * i <= n; i++){
        if (n % i == 0){
            resp += i;
            if (i != n / i) resp += n / i;
        }
    }
    int aux = func(resp);
    if(dp[resp] == -2 || resp == n || aux == -2) return dp[n] = -2;
    return dp[n] = 1 + aux;
}


int main(){
    fastio;
    ll t; cin >> t;
    while(t--){
        ll n; cin >> n;
        cont = 0;
        ll ans = func(n);
        if(ans == -2)cout << "otinifni" << endl;
        else cout << ans << endl;
    }

    return 0;
}