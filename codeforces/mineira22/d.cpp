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
const int MAXIMO = 0x3f3f3f3f;
const ll LMAXIMO = 0x3f3f3f3f3f3f3f3f;

int maxmin(int a, int b, int k, vector<vector<int>> &mat)
{
    bool filled = true;
    int maxV = 0;
    for (int i = a; i< a+k; i++){
        for (int j = b; j < b+k; j++){
            if (mat[i][j] == 0){
                filled = false;
                break;
            }
            maxV = max(maxV, mat[i][j]);
        }
    }

    return filled ? maxV : MAXIMO;
}

int main(){
    int n, m , k , q;
    cin >> n >> m >> k >> q;
    vector<vector<int>> mat(n, vector<int>(m, 0));
    int a, b, d;
    for(int i = 0; i < q; i++){
        cin >> a >> b >> d;
        a--;
        b--;
        mat[a][b] = d;
    }
    int v = MAXIMO;
    for(int i = 0; i < n-k+1; i++){
        for(int j = 0; j < m-k+1; j++){
            v = min(v, maxmin(i, j, k, mat));

        }
    }

    cout << (v == MAXIMO ? -1 : v) << endl;
    return 0;
}