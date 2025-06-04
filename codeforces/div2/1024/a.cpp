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

void solve(){
    int n, m, p, q; cin >> n >> m >> p >> q;
    // temos n-p+1 iterações que resultam em q, e o resultado de todas essas iterações tem que ser igual a m
    if((n-p+1) == m+(n-2)){ // se a soma de todas iterações for igual a quantidade de numeros que se repetem 2 vezes * m
        cout << "Yes" << endl;
    }
    else cout << "No" << endl;

    // cout << q * (n - p + 1) << " " << (n - 2) * m << endl;
    return;
}



int main(){
    fastio;
    int t; cin >> t;
    while(t--){
        solve();
    }


    return 0;
}