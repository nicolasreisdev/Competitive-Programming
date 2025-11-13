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

ll a[30][30];

ll dp(int n){
    //if(a[i][j] != -1) return a[i][j];
    for(int i = n; i>0; i--){
        for(int j = 0; j <= n;j++){
            if(i>=j){
                if(i == n && j == 1) continue;
                ll ans = 0;
                ll ans2 = 0;
                if(i == n) ans2 = 0;
                if(j == 0) ans = 0;
                if(j > 0){
                    for(int k = 1; k < j; k++){
                        //cout << i << " " << k << " " << a[i][k] << " " << a[n][k] << endl;
                        ans = max(a[i][k]+a[n][k], ans);
                    }
                    //cout << "fim" << endl;
                }
                if(i < n){      
                    for(int k = i+1; k <= n;k++){
                        ans2 = max(a[k][1] + a[k][j], ans2);
                    }
                
                }
                a[i][j] = ans + ans2;
            }
            else{
                ll resp = 0;
                for(int k = i; k <= j;k++){
                    resp = max(a[i][k] + a[k+1][j], resp);
                }   
                a[i][j] = resp;
            }
            //cout << i << " " << j << " " << a[i][j] << endl;
        }
    }
    return a[1][n];
}

int main(){
    fastio;

    int n, an1;
    while(cin >> n >> an1){
        memset(a, -1, sizeof(a));
        a[n][1] = an1;
        cout << dp(n) << endl;
    }

    return 0;
}