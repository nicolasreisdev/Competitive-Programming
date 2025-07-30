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

// ordenacao topologica com bfs

vector<int> list_adj[1];
long long grau[1] = {0};

void solve()
{

    int n, m, a, b, x;
    int count = 0;
    vector<int> order;

    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;
        list_adj[a].push_back(b);
        grau[b]++;
    }
    priority_queue<int> pq;
    for (int i = 1; i <= n; i++)
    {
        if (grau[i] == 0)
            pq.push(-i);
    }
    while (!pq.empty())
    {
        // cout << x << endl;
        x = -pq.top();
        pq.pop();
        count++;
        order.push_back(x);

        for (auto z : list_adj[x])
        {
            grau[z]--;
            if (grau[z] == 0)
            {
                pq.push(-z);
            }
        }
    }
    if (count < n){
        cout << -1;
    }
    else{
        for (int v : order)
            cout << v << " ";
    }
    cout << endl;
}

int main(){

}