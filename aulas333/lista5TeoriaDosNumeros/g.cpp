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
const int MAX = 0x3f3f3f3f;
const ll LMAX = 0x3f3f3f3f3f3f3f3f;



bool colinear(p a, p b, p c){
    return (b.f - a.f) * 1ll * (c.s - a.s)- (c.f - a.f) * 1ll * (b.s - a.s);
}


int n;

bool check(p v[], bool usei[]){
    int i1 = -1, i2 = -1;
    for(int i = 0; i < n;i++){
        if(usei[i]) continue;
        if(i1 == -1) i1 = i;
        else if(i2 == -1) i2 = i;
    }
    if(i2 == -1) return true;
    for(int i = 0; i < n;i++){
        if(usei[i]) continue;
        if(colinear(v[i1], v[i2], v[i])) return false;
    }
    return true;
}

bool solve(p a, p b, p v[]){
    bool usei[n];
    memset(usei, false, sizeof(usei));
    for(int i = 0; i < n;i++){
        if(!colinear(a, b, v[i])){
            usei[i] = true;
        }
    }

    return check(v, usei);
}

int main(){
    fastio;
    cin >> n;
    p v[n];
    for(int i = 0; i < n;i++){
        cin >> v[i].f >> v[i].s;
    }
    if(n <= 2){
        cout << "YES" << endl;
        return 0;
    }
    if(solve(v[0], v[1], v) || solve(v[0], v[2], v) || solve(v[1], v[2], v))cout << "YES" << endl;
    else cout << "NO" << endl;

    return 0;
}