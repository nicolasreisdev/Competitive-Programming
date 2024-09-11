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
    int n; cin >> n;
    vector<int> h(n);
    for(int i = 0; i < n; i++) cin >> h[i];
    vector<int> dp(n, MAX);
    dp[0] = 0;
    for(int i =1; i < n;i++){
        for(int j = max(0, i-2); j < i;j++){
            dp[i] = min(dp[i], dp[j] + abs(h[i] - h[j]));
        }
    }

    cout << dp[n-1] << endl;
    return 0;
}