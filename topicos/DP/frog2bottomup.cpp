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

    int n, k; cin >> n >> k;
    vector<int> h(n);
    for(int i = 0; i < n; i++) cin >> h[i];

    vector<int> dp(n);
    dp[0] = 0;
    for(int i = 1; i < n; i++){ // bottom up
        dp[i] = MAX; // initialize with infinity
        for(int j = max(0, i-k); j < i; j++){  // j é o ponto de onde eu vim
            dp[i] = min(dp[i], dp[j] + abs(h[i] - h[j])); // minimo entre o que eu tenho e o que eu posso ter
        }
    }

    cout << dp[n-1] << endl;

    return 0;
}