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

vector<int> moedas = {1, 5, 10, 25, 50}; // moedas disponíveis
ll dp[7500]; // valor do estado

ll solve(ll k){
    dp[0] = 1;

    for(int i = 0; i < moedas.size(); i++){
        for(int j = 0; j < k; j++){
            if(j + moedas[i] <= k) dp[j + moedas[i]] += dp[j];
        }
    }
    return dp[k];
}

int main(){
    fastio;

    ll n;
    while(cin >> n){
        memset(dp, 0, sizeof(dp));
        cout << solve(n) << endl;
    }


    return 0;
}