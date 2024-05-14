#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define rm pop_back
#define f first
#define s second

typedef pair<int, int> p;
typedef long long ll;
const int MAX = 1e5 + 10;
const ll INF = 1e15;

struct Seg{

    vector<ll> v;
    ll seg[4 * MAX];
    ll n;

    ll build(ll p, ll l, ll r){
        if (l == r)return seg[p] = v[l]; 
        int m = (l+r)/2;
        return seg[p] = min(build(2*p, l, m),build(2*p+1, m + 1, r));
    }

    void build(ll n2, vector<ll> &v2){
        n = n2;
        v = v2;
        build(1, 0, n-1);
    }
    ll query(ll a, ll b, ll p, ll l, ll r){
        if(b < l or a > r) return INF;
        if(a <= l and b >= r) return seg[p];
        int m = (l + r) / 2;
        return min(query(a, b, p*2, l, m), query(a, b, p*2+1, m + 1, r));
    }

    ll query(ll a, ll b){
        return query(a, b, 1, 0, n - 1);
    }
};

int main(){

    ll n; cin >> n;
    vector<ll> v(n);
    for(int i = 0; i < n;i++){
        cin >> v[i];
    }
    Seg seg;
    seg.build(n, v);
    ll q; cin >> q;
    while(q--){
        ll a, b; cin >> a >> b;
        cout << seg.query(a, b) << endl;
    }

    return 0;
}