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
const int MAX = 1e5 + 10;
const int MIN = 0;

vector<int> v;


void proc(map<pair<int,int>,int> &mp, int m){
    if(m==1){
        return;
    }
    for(auto i : mp){
        if(i.f.s == m){
            proc(mp, i.f.f);
            v.pb(i.s);
        }
    }
} 

int main()
{
    int n, m, a , b , c; cin >> n >> m;
    map<pair<int,int>,int> mp;
    for(int i = 0; i < m;i++){
        cin >> a >> b >> c;
        mp.insert({{a,b},c});
    }
    proc(mp, n);
    sort(v.begin(), v.end());
    for(auto i : v){
        cout << i << " ";
    }
    return 0;
}