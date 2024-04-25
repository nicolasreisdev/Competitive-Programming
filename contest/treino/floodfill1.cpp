#include <bits/stdc++.h>
using namespace std;

void floodfill(vector<vector<int>> v, int a, int b)
{
    if ((v[a][b] == 1 || v[a][b] == 3) && a > 0 && b > 0 && a < v.size() && b < v[0].size())
    {
        floodfill(v, a + 1, b);
        floodfill(v, a - 1, b);
        floodfill(v, a, b + 1);
        floodfill(v, a, b - 1);
    }
}



//----------------------------------------------------------------------------
//É geralmente encaixado em problemas de grafos, porém utiliza técnicas comuns em problemas que envolvem grid.
//Exemplo : Suponha que a matriz abaixo representa um parque, onde ‘G’ representa grama e ‘A’ representa água :
// GGGGGAAA
// GGGGAAAG 
// GGGGAAGG 
// GGGGGGGG
// GGGAAAGG 
// GGGGGGGG
// Pergunta : Qual a maior área composta apenas de água sabendo que você só pode se mover nas direções Norte, Sul, Leste e Oeste ?

                                                                                                                                                                                                                                                                                                                                                                                                              char grid[10][20];
bool val(int i, int j){
    return (i >= 0 && i < 10) && // 10 is the number of rows
           (j >= 0 && j < 20) && // 20 is the number of columns 
           grid[i][j] == 'A';
}

int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};
int vis[10][20];
int floodfill(int i, int j)
{
    if (vis[i][j])
        return 0;
    if(!val(i, j)) return 0;
    vis[i][j] = 1;
    int answer = 1;
    for (int i = 0; i < 4; ++i)
    {
        answer += floodfill(i + dr[i], j + dc[j]);
    }
    return answer;
}

//-------------------------------------------------------------------------------------------------