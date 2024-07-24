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

int dp[100010][100010];

int lcs(string a, string b, int n, int m){
    if(m == 0 || n == 0) return 0; // base case
    if(dp[m][n] != -1) return dp[m][n]; // if dp[m][n] is already calculated, return it
    if(a[m-1] == b[n-1]) return dp[m][n] = 1 + lcs(a, b, m-1, n-1); // if the last characters are equal, add 1 to the answer
    return dp[m][n] = max(lcs(a, b, m-1, n), lcs(a, b, m, n-1)); // if the last characters are different, return the maximum of the two possibilities
}


int main(){
    fastio;
    memset(dp, -1, sizeof(dp));
    string a, b; cin >> a >> b;
    int n = a.size(), m = b.size();
    cout << lcs(a, b, n, m) << endl;

    return 0;
}