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
ll ans = LMAX;
vector<int> sub;
vector<vector<p>> g;
vector<p> pathSubTree; 
vector<ll> melhor;
vector<ll> flag;
vector<bool> roots;
int flagAtual = 0;

void dfsAns(int u, int parent, int sum, int edges){
    if(sum > k) return;

    int rest = k - sum;
    if(flag[rest] == flagAtual){
        ans = min(ans, (ll)edges + melhor[rest]);
    }

    for(auto &[v, w]: g[u]){
        if(v != parent && !roots[v]){
            dfsAns(v, u, sum+w, edges+1);
        }
    }
}

void dfsMelhor(int u, int parent, int sum, int edges){
    if(sum > k) return;

    if(flag[sum] != flagAtual || edges < melhor[sum]){
        melhor[sum] = edges;
        flag[sum] = flagAtual;
    }

    for(auto &[v, w]: g[u]){
        if(v != parent && !roots[v]){
            dfsMelhor(v, u, sum+w, edges+1);
        }
    }
}

int subTree(int u, int parent){
    sub[u] = 1;

    for (auto &[v, w]: g[u])
        if (v != parent && !roots[v])
            sub[u] += subTree(v, u);

    return sub[u];
}

int centroid(int u, int parent, int size){

    for (auto &[v, w]: g[u])
        if (v != parent && sub[v] > size/2 && !roots[v])
            return centroid(v, u, size);

    return u;

}

void algorithm(int root){

    int n = subTree(root, -1);
    int newRoot = centroid(root, -1, n);

    flagAtual++;

    melhor[0] = 0;
    flag[0] = flagAtual;


    for(auto &[v, w]: g[newRoot]){
        if(!roots[v]){
            dfsAns(v, newRoot, w, 1);
            dfsMelhor(v, newRoot, w, 1);
        }
    }

    roots[newRoot] = true;

    for(auto &[v, w]: g[newRoot]){
        if(!roots[v]){
            algorithm(v);
        }
    }

}


int best_path(int N, int K, int H[][2], int L[]){

    n = N;
    k = K;

    g.assign(n, vector<p>());
    sub.resize(n);
    melhor.resize(k+1);
    flag.assign(k+1, 0);
    roots.assign(n, false);

    for(int i = 0; i < n-1;i++){ // constroi o grafo
        g[H[i][0]].pb({H[i][1], L[i]});
        g[H[i][1]].pb({H[i][0], L[i]});
    }


    algorithm(0);

    if(ans == LMAX) return -1;
    return ans;

}
