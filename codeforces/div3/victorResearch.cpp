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

    ll n, k;
    cin >> n >> k;
    map<ll, ll> v;
    v[0] = 1;
    ll ans = 0, sum = 0;
    for (int i = 0; i < n; i++){
        int x;
        cin >> x;
        sum += x;          // soma de prefixos
        ans += v[sum - k]; // se a posição de sum-k (se ja apareceu valor anteriormente, isto é, temos um intervalo que tem o valor k somado)
        cout << "sum: " << sum << " ans: " << ans << endl;
        v[sum]++;          // apareceu determinadas vezes
        cout << "valor map: " << v[sum] << endl;
    }
    cout << ans << endl;

    return 0;
}