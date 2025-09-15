#include <bits/stdc++.h>
#include "race.h"
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

int n, k;
vector<int> melhor;
ll ans;
vector<int> sub;
vector<vector<p>> g(n);
vector<p> pathSubTree; 
bool roots[n];

void dfsAns(int u, int parent, int sum){
    


    for(auto &[v, w]: g[u]){
        if(v != parent){
            dfsAns(v, u, sum+w);
        }
    }
}

void dfsMelhor(int u, int parent){

    for(auto &[v, w]: g[u]){
        if(v != parent){
            dfsMelhor(v, u);
        }
    }
}

int subTree(int u, int parent){
    sub[u] = 1;

    for (auto &[v, w]: g[u])
        if (v != parent)
            sub[u] += dfs(v, u);

    return sub[u];
}

int centroid(int u, int parent, int size){

    for (auto &[v, w]: g[u])
        if (v != parent and sub[v] > size/2)
            return dfs(v, u, size);

    return u;
}

void algorithm(int root){
    int n = subTree(centroid);
    int newRoot = centroid(root, -1, n);
    roots[newRoot] = true;
    for(auto &[v, w]: g[newRoot]){
        if(!roots[v]) algorithm(v);
    }
}


int best_path(int N, int K, int H[][2], int L[]){
    n = N;
    k = K;
    for(int i = 0; i < n-1;i++){
        g[H[i][0]].pb({H[i][1], L[i]});
        g[H[i][1]].pb({H[i][0], L[i]});
    }
    memset(roots, false, sizeof(roots));
    algorithm(0);
    if(ans == MAX) return -1;
    return ans;

    
    return N;

}
