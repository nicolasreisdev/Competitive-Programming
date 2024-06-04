#include <bits/stdc++.h>
using namespace std;

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
    int t; cin >> t;
    while(t--){
        int x, y, ans = 0, tot = 15; cin >> x >> y;
        bool flag = false;
        while(y >= 2 && !flag){
            y -= 2;
            x -= 7;
            ans++;
        }
        if(y < 2 && y > 0){
            ans++;
            x-=11;
            if(x <= 0) cout << ans << endl;
            else{
                while(x > 0){
                    x -= 15;
                    ans++;
                }
                cout << ans << endl;
            }
        }
        else if(x > 0){
            while(x > 0){
                x -= 15;
                ans++;
            }
            cout << ans << endl;
        }
        else cout << ans << endl;
        
    }
    return 0;
}