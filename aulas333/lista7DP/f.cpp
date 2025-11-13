#include <bits/stdc++.h>
using namespace std;

#define fastio  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
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

int dp[1010][1010];
bool ok[1010][1010];
int weight[1010], v[1010];

ll dpknap(int maxpes, int peso[], int val[], int n){
    if(n == 0 || maxpes == 0) return 0;
    if(!ok[n][maxpes]){
        if(peso[n-1] > maxpes) dp[n][maxpes] = dpknap(maxpes, peso, val, n-1);
        else dp[n][maxpes] = max(val[n-1] + dpknap(maxpes - peso[n-1], peso, val, n-1), dpknap(maxpes, peso, val, n-1));
        ok[n][maxpes] = 1;
    }
    return dp[n][maxpes];
}


int main(){
    fastio;
    int t; cin >> t;
    while(t){
        memset(dp, 0, sizeof(dp));
        memset(ok, 0, sizeof(ok));
        int n; cin >> n;
        for(int i = 0; i < n;i++){
            int p, w; cin >> p >> w; // valor e peso
            v[i] = p; 
            weight[i] = w;
        }
        int g; cin >> g;
        ll ans = 0;
        for(int i = 0; i < g; i++){
            int mw; cin >> mw; // peso maximo
            ans += dpknap(mw, weight, v, n);
        }
        cout << ans << endl;
        t--;
    }

    return 0;
}