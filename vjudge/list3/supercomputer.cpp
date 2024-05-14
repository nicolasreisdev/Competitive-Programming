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

    void update(ll i, ll v){
        while(i <= (ll)ft.size()){
            ft[i] += v;
            i += LSOne(i);
        }
    }

    ll rsq(ll j){
        ll sum = 0;
        while(j > 0){
            sum += ft[j];
            j -= LSOne(j);
        }
        return sum;
    }

    ll rsq(ll i, ll j) { return rsq(j) - rsq(i - 1); }
};

int main(){
    ll n, k; cin >> n >> k;
    BIT ft(n);
    while(k--){
      char c; cin >> c;
      if(c == 'F'){
        int a, b; cin >> a;
        ll val = ft.rsq(a,a);
        if(val % 2 == 0) ft.update(a, 1);
        else ft.update(a, -1);
      }else if (c == 'C'){
        ll a, b;
        cin >> a >> b;
        cout << ft.rsq(a,b) << endl;
      }  
    }
    return 0;
}