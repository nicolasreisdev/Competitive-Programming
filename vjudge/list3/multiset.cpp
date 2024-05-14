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
#define LSOne(S) ((S) & (-S))

class BIT{
private:
    vector<ll> ft;
public:
    BIT(int n){ft.assign(n+1, 0);}
    BIT(const vector<ll> &f){ft = f;}
    int rsq(int j){
        ll sum = 0;
        for(;j;j-=LSOne(j))sum+=ft[j];
        return sum;
    }

    int rsq(int i, int j) {return rsq(j) - rsq(i-1);}

    void add(int i, int v){
        for(; i < (int)ft.size(); i += LSOne(i)) ft[i] += v;
    }

};


int main(){
    int n, q; cin >> n >> q;
    BIT ft(n);
    for(int i = 1; i <= n;i++){
        int x; cin >> x;
        ft.add(x, 1); // adiciona 1 na posição x pois x <= n, logo x é um índice válido
    }
    while(q--){
        int c; cin >> c;
        if(c > 0){
            ft.add(c, 1); // c <= n
        }
        else{
            c = -c;
            int l = 1, r = n, ans = -1;
            while(l <= r){
                int m = (l+r)/2;
                if(ft.rsq(m) >= c){ // procura pelo c-ésimo elemento
                    ans = m;
                    r = m-1;
                }
                else l = m+1;
            }
            ft.add(ans, -1); 
        }
    }
    if(ft.rsq(n) == 0) cout << 0 << endl;
    else{
        int l = 1, r = n, ans = -1;
        while(l <= r){
            int m = (l+r)/2;
            if(ft.rsq(m) >= 1){ // procura por um elemento qualquer
                ans = m;
                r = m-1;
            }
            else l = m+1;
        }
        cout << ans << endl;
    }

    return 0;
}