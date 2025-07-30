/*
README
Aluno: Nicolas Eliel dos Reis Silva - Matrícula: 112703
Fontes de consulta: slides com propriedades de grafos simples
*/

#include <bits/stdc++.h>
using namespace std;

int main(){

    int t; cin >> t;
    while(t--){
        int n, m; cin >> n >> m;
        bool mat[n][m];
        bool flag = false;
        vector<int> grau(n), somacolun(m);
        vector<pair<int, int>> arestamult(m, pair<int,int> {-1, -1}); // vetor de arestas com pair de vertices
        memset(mat, false, sizeof(mat));
        for(int i = 0; i < n;i++){ // percorre as linhas
            for(int j = 0; j < m;j++){ // percorre as colunas
                cin >> mat[i][j];
                somacolun[j]+=mat[i][j]; // soma a quantidade de 1 na coluna
                grau[i]+=mat[i][j]; // soma o grau do vértice i
                if(mat[i][j]){ // caso o vértice i tenha aresta j
                    if(arestamult[j].first == -1)arestamult[j].first = i; // adiciona o vértice i como incidente de j
                    else arestamult[j].second = i; // adiciona o vértice i como incidente de j
                }
            }
        }
        map<pair<int, int>, int> test;
        for(int i = 0; i < m;i++){
            if (arestamult[i].first != -1 && arestamult[i].second != -1 && !test[{arestamult[i].first, arestamult[i].second}]){ // verifica se existe exatamente 2 vértices para
                // a aresta j, e se já existe aresta para esses dois  vértices 
                test[{arestamult[i].first, arestamult[i].second}] = 1; // incrementa a quantidade de arestas de i para j
            }
            else{ // caso tenha apenas um vértice ou já exista aresta anteriormente (aresta múltipla)
                flag = true; // sinalizamos que não é válido
            }
                
        }
        int impar = 0;
        for(int i = 0; i < n;i++){
            if(grau[i]%2==1){ // verifica se o grau do vértice i é impar
                impar++; // incrementa a quantidade de vértices impares
            }
        }
        if(impar%2==1){ // verifica se tem quantidade par de vértices impares (lema do aperto de mão)
            flag = true; // caso tenha quantidade impar de vértices de grau impar, sinalizamos que não é válido
        }
        for(int j = 0; j < m;j++){ // para cada coluna (aresta)
            if(somacolun[j] != 2){ // verificamos se a soma da coluna é diferente de 2  
                flag=true; // caso seja diferente de 2, sinalizamos que não é válido
            }
        }
        if(flag)cout << "No" << endl; // caso tenha sido sinalizado que não é valido
        else cout << "Yes" << endl; // caso seja valido
    }

    return 0;
}