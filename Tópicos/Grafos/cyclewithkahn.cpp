#include <bits/stdc++.h>
using namespace std;

void cycleWithKahn(vector<int> g[], int n){
    vector<int> grau(n, 0); 

    for(int i = 0; i < n; i++)
        for(int j: g[i]) grau[j]++; // grau de entrada

    queue<int> q;
    for(int i = 0; i < n; i++)
        if(grau[i] == 0) q.push(i); // se o grau de entrada for 0 (nao foi visitado por vertice adj), adiciona na fila

    int cont = 0;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        cont++; // conta quantos vertices foram visitados
        for(int i: g[u]){
            grau[i]--;
            if(grau[i] == 0) q.push(i);
        }
    }

    if(cont != n) cout << "Tem ciclo" << endl;
    else cout << "Não tem ciclo" << endl;
}

int main(){

}