#include <bits/stdc++.h>
using namespace std;

void dfs(vector<int> g[], int v, bool visitado[], stack<int> &pilha){
    visitado[v] = true;
    for(int i: g[v])
        if(!visitado[i])dfs(g, i, visitado, pilha); // se não foi visitado, faz a busca
    pilha.push(v); // adiciona na pilha o último elemento visitado (ou seja o que não tem mais adjacente não visitado)
}

void topologicalSort(vector<int> g[], int n){
    bool visitado[n];
    stack<int> pilha;

    for(int i = 0; i < n; i++) visitado[i] = false;

    for(int i = 0; i < n; i++)
        if(!visitado[i])dfs(g, i, visitado, pilha); // se não foi visitado, faz a busca

    while(!pilha.empty()){
        cout << pilha.top() << " ";
        pilha.pop();
    }
    cout << endl;
}

int main(){

}