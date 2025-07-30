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
#define LSOne(S) ((S) & -(S))

int main(){
    fastio;
    ll n, l , u;
    //int a = 100;
    //a = a | 59;
    //cout << a << endl;
    while (cin >> n >> l >> u){
        ll ans = 0, maxVal = 0;

        for(ll i = (1LL << 35); i > 0; i >>= 1){ // for com o bit mais significativo ligado 
            ll a = ans | i; // a vai receber o valor de ans com o bit i ligado
            if (a > u)continue; // se a for maior que u, pula para a proxima iteração
            else if (a <= l)ans = a; // se a for menor ou igual a l, ans recebe a
            else if ((n & i) > 0)continue; // verifica se o bit i de n é 1, se for pula para a proxima iteração
            else ans = a; 
        }
        cout << ans << endl;
    }



    return 0;
}