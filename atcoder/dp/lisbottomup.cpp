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

int main(){
    fastio;
    int dp[LMAX];
    string a; cin >> a;
    int lisMax = 0;

    memset(dp, -1, sizeof(dp));
    dp[0] = 1;
    for(int i = 0; i < a.size();i++){
        dp[i] = 1;
        for(int j = 0; j < i; j++){
            if(a[j] <= a[i]){
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        lisMax = max(lisMax, dp[i]);
    }
    cout << lisMax << endl;
    return 0;
}