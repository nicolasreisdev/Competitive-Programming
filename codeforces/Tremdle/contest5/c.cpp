#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);

typedef long long ll;
#define all(x) x.begin(), x.end()

struct dsu{
    vector<int> id, sz;

    dsu(int n) :id(n), sz(n,1){ iota(all(id), 0);}

    int find(int a) { return a == id[a] ? a : id[a] = find(id[a]);}

    void unite(int a, int b){
        a = find(a), b = find(b);
        if(a == b) return;
        if(sz[a] < sz[b]) swap(a, b);
        sz[a] += sz[b], id[b] = a;
    }
};



int main(){

    int n, m; cin >> n >> m;
    dsu dsu(n+1);
    for(int i = 0; i < m;i++){
        int qntd, x; cin >> qntd;
        if(qntd != 0){
            cin >> x; x--;
        }
        for(int j = 1; j < qntd;j++){
            int k; cin >> k;k--;
            dsu.unite(x, k);
        }
    }
    for(int i = 0; i < n;i++){
        cout << dsu.sz[dsu.find(i)] << " ";
    }
    cout << endl;
    return 0;
}