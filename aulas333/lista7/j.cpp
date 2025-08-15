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

ll dp[1010][1010];

ll lcs(string a, string b, ll i, ll j){
    if(i == 0 || j == 0) return 0; // base case
    if(dp[i][j] != -1) return dp[i][j];
    if(a[i-1] == b[j-1]) return dp[i][j] = 1 + lcs(a, b, i-1, j-1);
    return dp[i][j] = max(lcs(a, b, i-1, j), lcs(a, b, i, j-1)); 
}


int main(){
    fastio;
    string a, b;
    while(getline(cin, a)){
        getline(cin, b);
        memset(dp, -1, sizeof(dp));
        ll n = a.size(), m = b.size();
        cout << lcs(a, b, n, m) << endl;
    }
    return 0;
}