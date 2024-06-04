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

int main(){
    int n; cin >> n;
    vector<ll> v;
    for (int i = 0; i < n; i++){
        ll x; cin >> x;
        v.pb(x);    
    }
    // GULOSO E DP
    for(int i = 0; i < n;i++){
        if(i==1)v[i] = max(v[i], v[i-1]); // para não dar erro de segmentação
        else if(i>1)v[i] = max(v[i-1], v[i]+v[i-2]); // verifica o maximo entre o anterior e a soma do atual com o anterior
        
    }
    cout << v[v.size()-1] << endl;
    return 0;
}