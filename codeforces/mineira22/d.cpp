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

int n, m, k, q;
int mxd = 1, myd = 1, mxe = 1, mye = 1, mxf = 1, myf = 1;

void floodfill(vector<vector<bool>> &mat, int x, int y){
    if(x < 0 || x >= n || y < 0 || y >= m || mxd > k || mxe > k || myd > k || mye > k) return;
    floodfill(mat, x+1, y);
    mxd++;
    mxe--;
    mxf = max(mxf, mxd);
    floodfill(mat, x-1, y);
    floodfill(mat, x, y+1);
    floodfill(mat, x, y-1);
}

int main(){
    cin >> n >> m >> k >> q;
    vector<vector<bool>> mat(n, vector<bool>(m, false));
    int guard[n][m];
    for(int i = 0; i < q;i++){
        int x, y, d; cin >> x >> y >> d;
        x--; y--;
        guard[x][y] = d;
        mat[x][y] = true;
    }
    for(int i = 0; i < n;i++){
        for(int j = 0; j < m;j++){
            if(mat[i][j]){
                floodfill(mat, i, j);
            }
        }
    }


    return 0;
}