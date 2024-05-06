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

bool cmp(p a, p b){
    return a.f > b.f;
}


int main(){
    int n; cin >> n;
    vector<p> v;
    for(int i = 0; i < n;i++){
        int a, b; cin >> a >> b;
        v.pb({a, b});
    }
    ll sumh = 0, sumshoulder = 0;
    sort(v.begin(), v.end(), cmp);
    for (int i = 0; i < n; i++){
        sumh = sumshoulder + v[i].s;
        sumshoulder += v[i].f;
    }
    cout << sumh << endl;
    return 0;
}