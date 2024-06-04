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

int n, m;
int k, l;

int main(){
    cin >> n >> m;
    cin >> k >> l;
    char tab[n+1][m+1];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> tab[i][j];
        }
    }
    int cont = 0, maxcont = 0;
    pair<int,int> ans;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cont = 0;
            if(tab[i][j] == '.'){
                cout << "i: " << i << " j: " << j << endl;
                if(tab[i + k - 1][j + l - 1] == '*' && (i+k<n) && (j+l) < m){ // + k + l
                    cont++;
                }
                if (tab[i + k - 1][j - l - 1] == '*' && (i + k < n) && (j - l) > 0){ // + k - l
                    cont++;
                }
                if (tab[i - k - 1][j - l - 1] == '*' && (i - k - 1 > 0) && (j - l) > 0){ // - k - l
                    cont++;
                }
                if (tab[i - k - 1][j + l - 1] == '*' && (i - k - 1 > 0) && (j + l) < m){ // - k + l
                    cont++;
                }
                if (tab[i - l - 1][j - k - 1] == '*' && (i - k - 1 > 0) && (j - l - 1) > 0){ // - l - k
                    cont++;
                }
                if (tab[i - l - 1][j + k - 1] == '*' && (i + k - 1 < m) && (j - l - 1) > 0){ // - l + k
                    cont++;
                }
                if (tab[i + l - 1][j + k - 1] == '*' && (i + k - 1 < m) && (j + l - 1) < n){ // + l + k
                    cont++;
                }
                if (tab[i + l - 1][j + k - 1] == '*' && (i + k - 1 < m) && (j + l - 1) < n ){ // + l - k
                    cont++;
                }
                if (cont > maxcont){
                    cout << "cont: " << cont << endl;
                    maxcont = cont;
                    ans = {i+1, j+1};
                }
            }

        }
    }
    cout << ans.f << " " << ans.s << endl;

    return 0;
}