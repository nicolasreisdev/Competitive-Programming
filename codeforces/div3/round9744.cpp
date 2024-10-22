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
    
    int t; cin >> t;
    while(t--){
        int n, d, k; cin >> n >> d >> k;
        vector<ll> v(n+2, 0); // inicializa n com 0
        for(int i = 0; i < k;i++){
            int x, y; cin >> x >> y;
            v[max(0, x-d+1)]++; // inicio de intervalo
            v[y+1]--; // término de intervalo
        }
        ll ans = 0, brother = 0,brotherpos = 1,mom = MAX, mompos = n+1;
        for(int i = 1; i < (v.size()-d);i++){
            ans+=v[i];
            if(ans > brother) brotherpos = i, brother = ans;
            if(mom > ans) mom = ans, mompos = i;
        }
        cout << brotherpos << " " << mompos << endl;
    }

    return 0;
}



