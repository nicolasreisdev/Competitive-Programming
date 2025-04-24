#include <bits/stdc++.h>
using namespace std;




int main(){
    int n; cin >> n;

    vector<vector<int>> mat(n, vector<int>(n, 0));
    for(int i = 0; i < n;i++){
        for(int j = 0; j < n;j++){
            cin >> mat[i][j];   
        }
    }
    vector<vector<int>> newmat(n, vector<int>(n,0));
    double soma = 0;
    #pragma omp parallel for 
    for(int i = 0; i < n;i++){
        for(int j = 0; j < n;j++){
            for(int k = 0; k < n;k++){
                int m1 = mat[i][k];
                int m2 = mat[k][j];
                soma += m1+m2;
            }
        }
    }



    return 0;
}