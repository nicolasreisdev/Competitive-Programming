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
    int n, m; cin >> n >> m;
    string a, b; cin >> a >> b;
    int dp[n+1][m+1];

    for(int i = 0; i <= m;i++){
        for(int j = 0; j <= n;j++){
            if(i == 0 || j == 0) dp[j][i] = 0; // base case
            else if(a[j-1] == b[i-1]) dp[j][i] = 1 + dp[j-1][i-1]; // if the last characters are equal, add 1 to the answer
            else dp[j][i] = max(dp[j-1][i], dp[j][i-1]); // if the last characters are different, return the maximum of the two possibilities
        }
    }

    cout << dp[n][m] << endl;

    return 0;
}