/*
README
Aluno: Nicolas Eliel dos Reis Silva - Matrícula: 112703
Fontes de consulta: nenhuma.
*/

#include <bits/stdc++.h>
using namespace std;

// #define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
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



bool bipartide(vector<vector<int>> &g, int init){
    queue<int> fila;
    vector<int> cor(g.size(), -1);
    fila.push(init);
    cor[init] = 1;
    int white = 0, black = 1;
    while(!fila.empty()){
        int u = fila.front();
        fila.pop();
        for(int i: g[u]){
            if(cor[i] == -1){
                cor[i] = abs(1-cor[u]);
                fila.push(i);
            }
            else if(cor[i] == cor[u]) return false;
        }
    }
    return true;
}

int main(){

    return 0;
}