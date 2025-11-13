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

int main(){
    fastio;

    int n, x, y; cin >> n >> x >> y;
    vector<p> v;
    for(int i = 0; i < n;i++){
        int a, b; cin >> a >> b;
        v.pb({a, b});
    }
    bool visited[n];
    memset(visited, false, sizeof(visited));
    int ans = 0;
    for(int i = 0; i < n; i++){
        if(visited[i]) continue;
        visited[i] = true;
        ans++;
        int tx = v[i].f - x, ty = v[i].s - y;
        for (int j = 0; j < n; j++){
            if(visited[j]) continue;
            if(tx*(v[j].s - y) == ty*(v[j].f - x)){
                visited[j] = true;
            }
        }
    }
    cout << ans << endl;

    return 0;
}