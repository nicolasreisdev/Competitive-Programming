#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define rm pop_back
#define f first
#define s second

typedef pair<int, int> p;
typedef long long ll;
const int MAX = 110;

int n, m;
char M[MAX][MAX];
bool vis[MAX][MAX];
vector<pair<int,int>> mov = {{-1, 0}, {1,0}, {0,-1}, {0,1}};
bool val(pair<int,int> u){
    return u.f>=0 and u.s>=0 and u.f<n and u.s<m and M[u.f][u.s]=='H' and !vis[u.f][u.s];
}

pair<int,int> bfs(pair<int,int>s){
    queue<pair<int,int>>q;
    q.push(s);
    vis[s.f][s.s] = true;
    pair<int, int> v;
     while (!q.empty()){
        v = q.front();
        q.pop();

        for(auto e: mov){
            e.f += v.f;
            e.s += v.s; // new_i = e.f+v.f
            if(val(e)){
                q.push(e);
                vis[e.f][e.s] = true;
            }
        }
    }
    return v;
}

int main(){
    cin >> n >> m;
    pair<int,int>o;
    for(int i = 0; i < n;i++){
        for(int j = 0; j < m;j++){
            cin >> M[i][j];
            if(M[i][j] == 'o'){
                o = {i, j};
            }
        }
    }
    pair<int,int>ans = bfs(o);
    cout << ans.f+1 << " " << ans.s+1 << endl;
    
    return 0;
}