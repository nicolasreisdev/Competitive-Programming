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
    int n, x;cin >> n >> x;
    vector<int>v;
    for(int i = 0; i < n; i++){
        int a; cin >> a;
        v.pb(a);
    }
    int ans = v[0];
    for(int i  = 1;i < v.sz();i++){
        ans = __gcd(ans, v[i]);
    }
    if(x % ans == 0)cout << "YES" << endl;
    else cout << "NO" << endl;

    return 0;
}