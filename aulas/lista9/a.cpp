#include <bits/stdc++.h>
using namespace std;

//#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define endl '\n'
#define pb push_back
#define rm pop_back
#define f first
//#define s second
#define sz size
//#define in insert

typedef pair<int, int> p;
typedef long long ll;
const int MAX = 0x3f3f3f3f;
const ll LMAX = 0x3f3f3f3f3f3f3f3f;

int floydWarshalminmax(vector<vector<int>> &g, int s, int d){
    for(int k = 0; k < g.sz();k++){
        for(int i = 0; i < g.sz();i++){
            for(int j = 0; j < g.sz();j++){
                g[i][j] = max(g[i][j], min(g[i][k], g[k][j]));
            }
        }
    }
    return g[s][d];
}

int main(){
    //fastio;

    int n, r, e=1, z=0;
    cin >> n >> r;
    while(n != 0 && r != 0){
        //if(z > 0)cout << endl;
        vector<vector<int>> g(n+1, vector<int>(n+1, 0));
        for(int i = 0; i < r;i++){
            int a, b, p;
            cin >> a >> b >> p;
            g[a][b] = p;
            g[b][a] = p;
        }
        //cout << "aqui" << endl;   
        int s, d, t; cin >> s >> d >> t;
        int ans = floydWarshalminmax(g, s, d);
        //cout << ans << endl;
        cout << "Scenario #" << e++ << endl;
        ans--;// desconsidere o guia
        cout << "Minimum Number of Trips = " << ceil((double)t/(double)ans) << endl;
        cout << endl;
        cin >> n >> r;
    }

    return 0;
}