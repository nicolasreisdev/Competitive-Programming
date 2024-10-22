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

    int n; cin >> n;
    map<ll, ll> v;
    vector<p> vp;
    /*1 2
    1 2
    2 4
    3 4
    4 10
    */
    for(int i = 0; i < n;i++){
        int l,r ; cin >> l >> r;
        v[l]++;
        v[r+1]--;
        vp.pb({l,r});
    }
    ll ans = 0, maxinter = 0, maxinterpos = 0;
    for(auto [pos, w]: v){
        ans += w;
        if(ans > maxinter) maxinter = ans, maxinterpos = pos;
    }
    cout << endl;
    cout << maxinter << endl;
    for(int i = 0; i < vp.size();i++){
        if(vp[i].f ==  maxinterpos|| vp[i].s == maxinterpos){
            cout << i+1 << " ";
        }
    }
    cout << endl;

    return 0;
}