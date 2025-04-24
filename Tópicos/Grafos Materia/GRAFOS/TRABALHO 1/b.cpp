/*
README
Aluno: Nicolas Eliel dos Reis Silva - Matrícula: 112703
Fontes de consulta: materiais de programação competitiva 
*/

#include <bits/stdc++.h>
using namespace std;

void bipartide(vector<vector<long long>> &g, vector<long long> &color, long long v, long long &arestas){
    queue<long long> q; // fila de vértices
    q.push(v); // colocamos v na fila
    color[v] = 1; // inicializamos a cor de v como black
    long long white = 0, black = 1; // inicializamos o m e n
    while (!q.empty()){ // enquanto houver vértices
        long long u = q.front(); // pegamos o primeiro vértice da fila
        q.pop(); // removemos o vértice da fila
        for (auto e : g[u]){ // percorre os vizinhos do vértice u
            if (color[e] == -1){ // se o vizinho não foi visitado
                color[e] = abs(1 - color[u]); // colore o vizinho com a cor oposta a de u
                if (color[e] == 1) // caso a cor do vértice e seja black
                    black++;
                else // caso a cor do vértice e seja white
                    white++;
                q.push(e); // adiciona o vizinho na fila
            }
        }
    }
    cout << ((white*black)-arestas) << endl; // E = mxn (maximo de arestas que um bipartido pode ter) -> mxn - arestas que o grafo já possui
} 



int main(){
    long long n; cin >> n;
    vector<vector<long long>> g(n+1); // first = cor, second = adjacentes
    vector<long long> color (n+1, -1); // cores dos vértices, inicializado com -1 para simbolizar que ainda não há cor
    long long a, b, cont = 0;
    for(long long i = 0; i < n-1; i++){
        cin >> a >> b;
        cont++; // contabiliza a quantidade de ruas
        g[a].push_back(b); // cria a aresta de a para b
        g[b].push_back(a); // cria a aresta de b para a
    }
    bipartide(g, color, 1, cont);
    

    return 0;
}