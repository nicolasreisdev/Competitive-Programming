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
    int n, k, cont = 0; cin >> n >> k;
    vector<int> v;
    for(int i = 1; i <= n;i++){
        int x; cin >> x;
        v.pb(x);
    }
    for(int i = 0; i < n; i++){
        if(v[i] >= v[k-1] && v[i] > 0)cont++;
    }
    cout << cont << endl;
    return 0;
}