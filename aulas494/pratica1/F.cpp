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

int timer = 0;
void eulerTour(vector<vector<ll>> &g, int v, int parent, vector<int> &start, vector<int> &end){
    start[v] = timer;
    timer++;
    for(int u: g[v]) if(u!=parent) eulerTour(g, u, v, start, end);
    end[v] = timer;
}

    int main(){
    fastio;

    int n; cin >> n;
    vector<ll>values(n+1);
    vector<vector<ll>> g(n+1);
    vector<int> start;
    vector<int> end;
    for(int i = 1; i <= n;i++){
        cin >> values[i];
    }
    for(int i = 2; i <= n;i++){
        int parent; cin >> parent;
        g[parent].push_back(i);
        g[i].push_back(parent);
    }
    eulerTour(g, 1, 0, start, end);
    return 0;
}