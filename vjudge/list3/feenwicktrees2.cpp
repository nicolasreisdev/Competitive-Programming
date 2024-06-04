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

    ll build(int p, int l, int r){
        if (l == r)return seg[p] = v[l];
        int m = (l + r) / 2;
        return seg[p] = (build(2*p, l, m) + build(2*p+1, m + 1, r));
    }

    void build(ll n2, vector<ll> &v2){
        n = n2;
        v = v2;
        build(1, 0, n - 1);
    }

    ll query(int a, int b, int p, int l, int r){
        if (a > r or b < l)return 0;
        if( a <= l and r >= b)return seg[p];
        int m = (l + r) / 2;
        return (query(a, b, p*2, l, m)+query(a, b, p*2+1, m + 1, r));
    }

    ll query(int a, int b){
        for(int i = 0; i < 4 * n; i++)cout << seg[i] << " ";
        cout << endl;
        return query(a, b, 1, 0, n - 1);
    }

    ll update(int i, int x, int p, int l, int r){
        if (i < l or i > r)return seg[p];
        if (l == r)return seg[p] += x;
        int m = (l + r) / 2;
        return seg[p] = (update(i, x, 2 * p, l, m ) + update(i, x, 2*p + 1, m + 1, r));
    }

    ll update(int i, int x){
        return update(i, x, 1, 0, n - 1);
    }
};

int main(){
    ll n;
    cin >> n;
    vector<ll> f(n);
    for (int i = 0; i < n; i++){
        cin >> f[i];
    }
    Seg ft;
    ft.build(n, f);
    int q;
    /*cin >> q;
    while (q--){
        char c;
        cin >> c;
        if (c == 'u'){
            int i, v;
            cin >> i >> v;
            ft.update(i-1, v);
        }
        else if (c == 'q'){ 
            int a, b;
            cin >> a >> b;
            a--;b--;
            cout << ft.query(a, b) << endl;
        }
    }*/


    return 0;
}