#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define fastio ios_base::sync


typedef long long ll;

int main(){

    int n; cin >> n;
    int row[n];
    int column[n];
    memset(row, 0, sizeof(row));
    memset(column, 0, sizeof(column));
    for(int i = 0; i < n;i++){
        for(int j = 0; j < n;j++){
            char c; cin >> c;
            if(c == 'C'){
                row[i]++;
                column[j]++;
            }
        }
    }

    ll ans = 0;
    for(auto e: row)ans += (e*(e-1))/2;
    for(auto e: column)ans += (e * (e - 1)) / 2;
    
    cout << ans << endl;
    return 0;
}