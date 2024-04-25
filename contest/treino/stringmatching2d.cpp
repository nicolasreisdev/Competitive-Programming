#include <bits/stdc++.h>
using namespace std;

//Outro problema que também é modelado como grid.Seu desafio é encontrar uma string(pattern)
// dentro de uma matriz de caracteres.Suponha a matriz abaixo : 
// abcefgh
// bblamco
// oprixasd
// ureikjhpl
// kadtrlmp
// Dado que somente é possível percorrer a matriz nas direções Norte,  Sul, Leste, Oeste, Noroeste, Nordeste, Sudeste e Sudoeste
// a palavra “abrir” existe no grid ?

bool val(int i, int j){
    return (i >= 0 && i < 10) && // 10 is the number of rows
           (j >= 0 && j < 20) && // 20 is the number of columns
           grid[i][j] == 'A';
}

int dr[] = {-1, 1, 0, 0, -1, -1, 1, 1}; // agora temos 8 opções
int dc[] = {0, 0, -1, 1, 1, -1, 1, -1};
int vis[10][20];
char grid[10][20];
string pattern;
int find(int i, int j, int pos){
    if (pos == (int)pattern.size())
        return 1;
    if(!val(i, j)) return 0;
    if (vis[i][j] != -1)
        return vis[i][j];
    vis[i][j] = 0;
    if (grid[i][j] == pattern[pos]){
        for (int i = 0; i < 8; ++i){
            vis[i][j] = vis[i][j] || find(i + dr[i], j + dc[j], pos + 1);
            if(vis[i][j]) return 1;
        }
    }
    return 0;
}