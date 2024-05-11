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

#define LSOne(S) ((S) & -(S))

class BIT{
private:
    vector<ll> ft;

public:
    BIT(int n) { ft.assign(n + 1, 0); }

    BIT(const vector<ll> &f){
        int n = (int)f.size() - 1;
        ft.assign(n + 1, 0);
        for (int i = 1; i <= n; ++i){
            ft[i] += f[i];
            if (i + LSOne(i) <= n){
                ft[i + LSOne(i)] += ft[i];
            }
        }
    }

    ll rsq(int j){
        ll sum = 0;
        for (; j; j -= LSOne(j))
            sum += ft[j];
        return sum;
    }

    ll rsq(int i, int j) { return rsq(j) - rsq(i - 1); }

    void update(int i, ll v){
        for (; i < (int)ft.size(); i += LSOne(i)){
            ft[i] += v;
        }
    }
};

int main(){
    int n; cin >> n;
    vector<ll> f(n+1, 0);
    f[0] = 0;
    for(int i = 1; i <= n; i++){
        int x; cin >> x;
        f[i] = x;
    }
    BIT ft(f);
    int q; cin >> q;
    while(q--){
        char a; cin >> a;
        if(a == 'u'){
            ll i, v; cin >> i >> v;
            ft.update(i, v);
        }
        else if(a == 'q'){
            int i, j; cin >> i >> j;
            cout << ft.rsq(j) << endl;
        }
    }


    return 0;
}