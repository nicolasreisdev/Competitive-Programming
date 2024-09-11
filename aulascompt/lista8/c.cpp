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


int comp(int v[]){
    return v[0] * 1000 + v[1] * 100 + v[2] * 10 + v[3];
}


void descomp(int n, int v[]){
    v[0] = n / 1000;
    v[1] = (n / 100) % 10;
    v[2] = (n / 10) % 10;
    v[3] = (n) % 10;
}

int minDist(int initial, int target, int proibid[], int visited[]){
    if (proibid[initial] || proibid[target]) return -1;

    queue<p> q;
    q.push({initial, 0});
    visited[initial] = true;
    while (!q.empty()){
        auto [next, dist] = q.front();
        q.pop();

        if (next == target)return dist;
        int wheel[4];
        descomp(next, wheel);
        for (int i = 0; i < 4; i++){
            wheel[i] = (wheel[i] + 1) % 10; // gira para a direita
            int w = comp(wheel);
            if (!proibid[w] && !visited[w]){ // caso nao seja proibido e nao tenha sido visitado
                q.push({w, dist + 1});
                visited[w] = true;
            }

            wheel[i] = (wheel[i] - 2 + 10) % 10; // gira para a esquerda
            w = comp(wheel);
            if (!proibid[w] && !visited[w]){
                q.push({w, dist + 1});
                visited[w] = true;
            }
            wheel[i] = (wheel[i] + 1 + 10) % 10; // volta para a posicao original
        }
    }
    return -1;
}



int main(){
    int t; cin >> t;
    int visited[10010];
    int proibid[10010];
    while(t){
        memset(proibid, 0, sizeof(proibid));
        memset(visited, 0, sizeof(visited));

        int wheel[4];
        for(int i = 0; i < 4; i++) cin >> wheel[i];
        int initial = comp(wheel);
        for(int i = 0; i < 4; i++) cin >> wheel[i];
        int target = comp(wheel);

        int m; cin >> m;
        for (int p = 0; p < m; p++){
            for(int i = 0; i < 4; i++) cin >> wheel[i];
            proibid[comp(wheel)] = true;
        }

        int dist = minDist(initial, target, proibid, visited);
        cout << dist << "\n";
        
        t--;
    }
}
