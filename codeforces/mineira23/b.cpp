#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define rm pop_back
#define f first
#define s second
#define sz size
#define in insert

typedef pair<int, int> p;
typedef long long ll;
const int MAX = 0x3f3f3f3f;
const ll LMAX = 0x3f3f3f3f3f3f3f3f;

int main(){
    int n, m; cin >> n >> m;
    int v[n][m];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> v[i][j];
        }
    }
    int sum = 0, result, ans = 0;
    for(int i = 0; i < n;i++){ // linhas
        sum = 0;
        for(int j = 1; j < m;j++){ // colunas
            result = abs(v[i][j] - v[i][j-1]);
            if(result <= 1){ // se a diferença entre os elementos for menor ou igual a 1 e o elemento anterior for igual ao guardado, soma
                sum++;
            }
            else {
                ans = max(sum, ans);
                sum = 0;
            }
        }
        ans = max(sum, ans);
    }
    for (int i = 0; i < m; i++){ // colunas
        sum = 0;
        for (int j = 1; j < n; j++){ // linhas
            result = abs(v[j][i] - v[j-1][i]); 
            if(result <= 1){ // se a diferença entre os elementos for menor ou igual a 1, soma
                sum++;
            }
            else{
                ans = max(sum, ans);
                sum = 0;
            }
        }
        ans = max(sum, ans);
    }
    cout << ans+1 << endl;

    return 0;
}