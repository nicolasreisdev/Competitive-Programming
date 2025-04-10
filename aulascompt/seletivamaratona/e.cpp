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
 

typedef pair<int,int>p;
typedef long long ll;
const int MAX = 0x3f3f3f3f;
const ll LMAX = 0x3f3f3f3f3f3f3f3f;

struct pt {
    int x, y;
    pt(int x_ = 0, int y_ = 0) : x(x_), y(y_) {}
    pt operator - (const pt p) const { return pt(x-p.x, y-p.y); }
    ll operator ^ (const pt p) const {return x*(ll)p.y - y*(ll)p.x;}
};

ll sarea2(pt p, pt q, pt r){
    return (q-p)^(r-q);
}


int main(){
    fastio;
    
    int n, x, y; cin >> n >> x >> y;
    vector<pt> v;
    bool visit[n+10];
    memset(visit, false, sizeof(visit));
    pt init (x, y);
    for(int i = 0; i < n;i++){
        int a, b; cin >> a >> b;
        v.push_back({a, b});
    }
    ll ans = 0;
    for(int i =0; i < n;i++){
        if(visit[i]){
            continue;
        }
        ans++;
        for(int j = i+1; j < n;j++){
            if(sarea2(init, v[i], v[j]) == 0){
                visit[j] = true;
            }
        }
    }

    cout << ans << endl;



    return 0;
}