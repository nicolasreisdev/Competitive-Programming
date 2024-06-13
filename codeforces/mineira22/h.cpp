#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int comp(pair<pair<int, int>, pair<int, int>> a, pair<pair<int, int>, pair<int, int>> b){
    return a.first.first > b.first.first || (a.first.first == b.first.first && a.first.second < b.first.second);
}

vector<pair<pair<int, int>, pair<int, int>>> searcchAdj(int x, int y, vector<vector<int>> &mat)
{
    int l = mat.size();
    int c = mat[0].size();
    vector<pair<pair<int,int>, pair<int, int>>> lista;
    for (int i = -1; i <= 1; i++)
        for (int j = -1; j <= 1; j++){
            if (i == 0 && j == 0)
                continue;
            if (x + i < 0 || x + i >= l)
                continue;
            if (y + j < 0 || y + j >= c)
                continue;

            int soma;
            if (i == -1)soma = 3;
            if (i == 0){
                if (j == -1)soma = 2;
                if (j == 1)soma = 4;
            }
            if (i == 1){
                if (j == -1)soma = 9;
                if (j == 0)soma = 7;
                if (j == 1)soma = 5;
            }
            
            lista.push_back({{mat[x + i][y + j], j+soma}, {x + i, y + j}});
        }

    sort(lista.begin(), lista.end(), comp);

    return lista;
}

// void print(vector<vector<int>> &mat)
// {
//     int l = mat.size();
//     int c = mat[0].size();
//     for (int i = 0; i < l; i++)
//     {

//         for (int j = 0; j < c; j++)
//             cout << mat[i][j] << " ";
//         cout << endl;
//     }
// }

int main(){
    int l, c;
    cin >> l >> c;
    vector<vector<int>> mat(l, vector<int>(c));
    for (int i = 0; i < l; i++)
        for (int j = 0; j < c; j++)
            cin >> mat[i][j];

    int x, y;
    cin >> x >> y;
    x--; y--;
    
    int numVis = 1;
    int atx = x;
    int aty = y;
    while (numVis < l + c + 1){
        auto adj = searcchAdj(atx, aty, mat);
        int giv = floor(mat[atx][aty] / adj.size());
        int fica = mat[atx][aty] % adj.size();
        mat[atx][aty] = fica;
        auto nxt = adj[0];
        for (auto &v : adj){
            //cout << v.first.first << " " << v.first.second << endl;
            mat[v.second.first][v.second.second] += giv;
        }
        
        atx = adj[0].second.first;
        aty = adj[0].second.second;

        //cout << atx + 1 << " " << aty + 1 << endl;

       
        numVis++;
        
        
    }
    int vm = INT32_MIN;
    for (int i = 0; i < l; i++)
        for (int j = 0; j < c; j++)
            vm = max(vm, mat[i][j]);

    cout << vm << endl;
    return 0;
}