/*
README
Aluno: Nicolas Eliel dos Reis Silva - Matrícula: 112703
Fontes de consulta: nenhuma
*/



#include <bits/stdc++.h>    
using namespace std;


const int MAX = 2*(1e5+10); // maximo de 2*10^5
bool visitado[MAX];

void dfs(vector<pair<int, vector<int>>> &g, int v, int &k, int &cont, int consec){
    visitado[v] = true; // sinaliza que o vértice v foi visitado
    if(g[v].first){ // verifica se há jacare nesse vértice
        consec++; // caso tenha jacaré, incrementa a quantidade de jacarés consecutivos
        if(consec > k) return; // caso Capivaristo lute com mais que k jacarés no caminho até x    
    }
    else{ // caso não tenha
        consec = 0; // começamos novamente a contagem de jacarés consecutivos
    }
    for(auto nextv: g[v].second){
        if(!visitado[nextv]){ // caso v tenha filhos que não foram visitados
            dfs(g, nextv, k, cont, consec); // chama a busca em profundidade para os vértices adjacentes
        }
        else if(g[v].second.size() == 1 && visitado[nextv]){ // caso já foi visitado, temos que v é uma folha e possui apenas um vértice adjacente que já foi visitado, logo
            cont++; // Capivaristo consegui chegar em uma sala de aula
        }
    }
}



int main(){
    int n, k; cin >> n >> k;
    vector<pair<int, vector<int>>> g(n+1); // lista com first = possui jacare e second = adjacentes
    memset(visitado, false, sizeof(visitado)); // inicializa o vetor de visitados como falso
    for(int i = 1; i <= n;i++){
        int x; cin >> x;
        g[i].first = x; // leitura para caso tenha jacaré ou não
    } 
    for(int i = 0; i < n-1;i++){
        int a, b;
        cin >> a >> b; 
        g[a].second.push_back(b); // adiciona b adjacente a
        g[b].second.push_back(a); // adiciona a adjacente b
    }
    int ans = 0; // valor de salas
    dfs(g, 1, k, ans, 0);
    cout << ans << endl;


    return 0;
}