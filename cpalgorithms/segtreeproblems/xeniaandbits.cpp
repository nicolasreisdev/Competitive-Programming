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
const int MAX = 1e5 + 10;
const ll LMAX = 0x3f3f3f3f3f3f3f3f;


struct Seg{

    vector<ll> v;
    ll seg[4*MAX];
    ll n;

    ll build(ll p, ll l, ll r, bool op){
        if(l == r){
            return seg[p] = v[l]; // folha
        }
        ll m = (l+r)/2;

        if(op) return seg[p] = build(2 * p, l, m, !op) | build(2 * p + 1, m + 1, r, !op);
        else return seg[p] = build(2 * p, l, m, !op) ^ build(2 * p + 1, m + 1, r, !op);
        
    }
    
    void build(ll n2, vector<ll> v2, bool op2){
        n = n2;
        v = v2;
        build(1, 0, (1 << n)-1, op2);
    }

    ll update(ll i, ll x, ll p, ll l, ll r, bool op){
        if (i < l or i > r) return seg[p];
        if (l == r) return seg[p] = x;
        ll m = (l + r) / 2;
        if(op) return seg[p] = update(i, x, 2 * p, l, m, !op) | update(i, x, 2 * p + 1, m + 1, r, !op);
        else return seg[p] = update(i, x, 2 * p, l, m, !op) ^ update(i, x, 2 * p + 1, m + 1, r, !op);
    }

    void update(ll i , ll x, bool op){
        update(i, x, 1, 0, (1 << n) - 1, op);
    }

};





int main(){
    fastio;

    
    int n, m; cin >> n >> m;
    vector<ll> v;
    Seg seg;


    for(int i = 0; i < (1 << n); i++){
        ll x; cin >> x;
        v.pb(x);
    }
    
    seg.build(n, v, n % 2 == 0 ? false : true);

    for(int i = 0; i < m; i++){
        ll p, b; cin >> p >> b;
        seg.update(p - 1, b, n % 2 == 0 ? false : true);
        cout << seg.seg[1] << endl;
    }


    return 0;
}