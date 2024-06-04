#include <bits/stdc++.h>
using namespace std;

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

int dijkstra(vector<p> adj[], int n, int s, int d){
    priority_queue<p, vector<p>, greater<p>> pq;
    vector<int> dist(n, MAX);
    pq.push({0, s});
    dist[s] = 0;
    while(!pq.empty()){
        int u = pq.top().s;
        pq.pop();
        for(auto x : adj[u]){
            int v = x.f;
            int w = x.s;
            if(dist[v] > dist[u] + w){
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
    return dist[d];
}

int main(){
    int n, k; cin >> n >> k;
}