/*
README
Aluno: Nicolas Eliel dos Reis Silva - Matrícula: 112703
Fontes de consulta: material de programação competitiva
*/

#include <bits/stdc++.h>
using namespace std;

int floodfill(vector<string> &m, int &value, int i, int j){
    if(i < 0 || i>= m.size() || j < 0 || j >= m[0].size()) return 0; // Caso esteja fora da matriz
    if(m[i][j] == '.') value++; // se for uma celula vazia
    if(m[i][j] == '#') return 0; // caso tenha jacaré, retorna 0
    m[i][j] = '#'; // "pinta" a celula para não passar por ela novamente
    floodfill(m, value, i+1, j); // chama a função para as celulas vizinhas
    floodfill(m, value, i-1, j); // chama a função para as celulas vizinhas
    floodfill(m, value, i, j+1); // chama a função para as celulas vizinhas
    floodfill(m, value, i, j-1); // chama a função para as celulas vizinhas
    return value;
}



int main(){

    int t, number = 1; cin >> t; 
    while(t--){
        int l, h; cin >> l >> h;
        vector<string> m;
        for(int i = 0; i < h; i++){
            string x; cin >> x; // lê a linha
            m.push_back(x); // adiciona a linha na matriz
        }
        int initx, inity;
        for(int i = 0; i< h;i++){
            for(int j= 0; j < l;j++){
                if(m[i][j]=='@') { // encontra o local onde Capivaristo se encontra
                    initx = i;
                    inity = j;
                }
            }
        }

        int ans = 1; // inicia com 1 pois a celula onde Capivaristo está conta
        ans = floodfill(m , ans, initx, inity); // chama a função de floodfill
        cout << "Case " << number << ": " << ans << endl;
        number++;
    }


    return 0;
}