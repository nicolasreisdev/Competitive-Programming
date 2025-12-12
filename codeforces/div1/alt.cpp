#include <bits/stdc++.h>
using namespace std;

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
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

int main()
{
    fastio;


    int n, m; cin >> n >> m;
    vector<vector<int>> g(n);
    vector<p> citizens;
    for(int i = 0; i < n-1; i++){
        int u, v; cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }

    for(int i = 0; i < m;i++){
        int x, y; cin >> x >> y;
        citizens.pb({x, y});
    }
    

    return 0;
}