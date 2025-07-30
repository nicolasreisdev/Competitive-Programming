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

ll dp[100010][4];

int main(){
    fastio;

    int n;
    cin >> n;
    vector<int> swim(n + 1), mount(n + 1), hmwork(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> swim[i] >> mount[i] >> hmwork[i];

    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= n; i++){
        dp[i][1] = max(dp[i - 1][2] + mount[i], dp[i - 1][3] + hmwork[i]);
        dp[i][2] = max(dp[i - 1][1] + swim[i], dp[i - 1][3] + hmwork[i]);
        dp[i][3] = max(dp[i - 1][1] + swim[i], dp[i - 1][2] + mount[i]);
    }

    cout << max({dp[n][0], dp[n][1], dp[n][2]}) << endl;

    return 0;
}