#include <bits/stdc++.h>
using namespace std;


#define fastio ios_base::sync_with_stdio(0); cin.tie(0);
#define endl '\n'
#define all(x) x.begin(),  x.end()

const int MAX = 4*1e6;
typedef long long ll;


int main(){
    fastio;
    int n; cin >> n;
    vector<int> v;
    for(int i = 0; i < n;i++){
        int x; cin >> x; v.push_back(x);
    }

    ll dp[MAX];
    memset(dp, -1, sizeof(dp));
    ll lisMax = 0;
    dp[0] = 1;
    for (int i = 0; i < v.size(); i++){
        dp[i] = 1;
        for (int j = 0; j < i; j++){
            if (v[j] <= v[i]){
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        lisMax = max(lisMax, dp[i]);
    }

    return 0;
}