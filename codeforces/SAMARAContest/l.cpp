#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    string s; cin >> s;
    int n; cin >> n;
    string x = "";
    cin.ignore();
    while(n--){
        string query; getline(cin, query);
        if(query == "pop"){
            x.pop_back();
        }
        else{
            x.insert(x.end(), query[5]);
        }

        int n = s.size(), m = x.size();
        int dp[n+1][m+1];

        for(int i = 0 ;i <= m;i++){
            for(int j = 0; j <= n;j++){
                if(i == 0 || j == 0) dp[j][i] = 0;
                else if(s[j-1] == x[i-1]) dp[j][i] = 1 + dp[j-1][i-1];
                else dp[j][i] = max(dp[j-1][i], dp[j][i-1]);
            }
        }

        if(dp[n][m] == m) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}