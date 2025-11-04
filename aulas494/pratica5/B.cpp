#include <bits/stdc++.h>
using namespace std;

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define endl '\n'
#define pb push_back
#define f first
#define s second
#define sz size

typedef pair<int, int> p;
typedef long long ll;
const int MAX = 0x3f3f3f3f;
const ll LMAX = 0x3f3f3f3f3f3f3f3f;

map<p, map<ll, ll>> mp;
ll ans, n, m, mid, total, k;

void paths1(int x, int y, int steps,  ll v, vector<vector<ll>> &matriz){
    if (x >= n || y >= m ) return;
    if(steps == mid){
        mp[{x, y}][v]++;
        return;
    }
    if(y + 1 < m) paths1(x, y + 1, steps + 1, v^matriz[x][y+1], matriz);
    if(x + 1 < n) paths1(x + 1, y, steps + 1, v ^ matriz[x+1][y], matriz);
}

void paths2(int x, int y, int steps, ll v,  vector<vector<ll>> &matriz){
    if(x < 0 || y < 0) return;
    if (steps == (total-mid)){
        ll help = k ^ v ^ matriz[x][y];
        if(mp.count({x, y})){
            if(mp[{x, y}].count(help))
                ans += mp[{x, y}][help];
        } 
    
        return;
    }
    if (y > 0)paths2(x, y - 1, steps + 1,  v ^ matriz[x][y-1], matriz);
    if (x > 0)paths2(x - 1, y, steps+1,  v ^ matriz[x-1][y], matriz);
}

int main(){
    fastio;

    cin >> n >> m >> k;
    vector<vector<ll>> matriz(n, vector<ll>(m));
    for(int i = 0; i < n;i++)
        for(int j = 0; j < m;j++) cin >> matriz[i][j]; 
    
    total = (n-1) + (m-1);
    mid = total/2;
    
    paths1(0, 0, 0, matriz[0][0], matriz);
    paths2(n-1, m-1, 0, matriz[n-1][m-1], matriz);
    cout << ans << endl;


    return 0;
}