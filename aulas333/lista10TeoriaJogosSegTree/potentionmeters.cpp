#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define endl '\n'
#define pb push_back
#define rm pop_back
#define f first
//#define s second
#define sz size
#define in insert

typedef pair<int, int> p;
typedef long long ll;
const int MAX = 200000;
const ll LMAX = 0x3f3f3f3f3f3f3f3f;


struct Seg{

    vector<ll> v;
    ll seg[4 * MAX];
    ll n;

    ll build(ll p, ll l, ll r){
        if (l == r)
            return seg[p] = v[l];
        int m = (l + r) / 2;
        return seg[p] = build(2 * p, l, m)+build(2 * p + 1, m + 1, r);
    }

    void build(ll n2, vector<ll> &v2){
        n = n2;
        v = v2;
        build(1, 0, n - 1);
    }
    ll query(ll a, ll b, ll p, ll l, ll r){
        if (b < l or a > r)
            return 0;
        if (a <= l and b >= r)
            return seg[p];
        int m = (l + r) / 2;
        return query(a, b, p * 2, l, m)+query(a, b, p * 2 + 1, m + 1, r);
    }

    ll query(ll a, ll b){
        return query(a, b, 1, 0, n - 1);
    }

    void update(ll idx, ll val, ll p, ll l, ll r){
        if (l == r){
            seg[p] = val;
            return;
        }
        int m = (l + r) / 2;
        if (idx <= m)
            update(idx, val, 2 * p, l, m);
        else
            update(idx, val, 2 * p + 1, m + 1, r);
        seg[p] = seg[2 * p] + seg[2 * p + 1];
    }

    void update(ll idx, ll val){
        update(idx, val, 1, 0, n - 1);
    }
};


int main(){
    fastio;

    ll n, t = 1, z = 0;
    while(cin >> n && n){
        if(z) cout << endl;
        vector<ll> v(n+1);
        for(int i = 0; i < n;i++){
            cin >> v[i];
        }
        Seg seg;
        seg.build(n, v);

        cout << "Case " << t << ":" << endl;
        t++;
        while(true){
            string s; cin >> s;
            if(s == "END") break;
            ll a, b; cin >> a >> b;
            if(s == "S"){
                seg.update(a-1, b);
            }
            else{
                cout << seg.query(a-1, b-1) << endl;
            }
        }
        z++;
    }


    return 0;
}