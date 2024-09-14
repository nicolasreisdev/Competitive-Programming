#include <bits/stdc++.h>
using namespace std;

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
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

    int t;
    cin >> t;
    while (t--){
        int x, y, k; cin >> x >> y >> k;
        int ans = 0;
        if(x/k > y/k) ans += (2*ceil((x/k)))-1;
        else ans += 2*ceil((y/k));
        cout << ans << endl;

    }

    return 0;
}