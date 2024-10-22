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
    int x1, y1, x2, y2;cin >> x1 >> y1 >> x2 >> y2;
    ll ans = 0;
    if((y1 == 0 && x1 < x2) || (y2 >= y1 && x1 < x2)){
        cout << -1 << endl;
        return 0;
    }
    while(x1 <= x2){
        x1+=y1;
        x2+=y2;
        ans++;
    }

    cout << ans << endl;

    return 0;
}