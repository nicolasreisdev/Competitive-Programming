#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define endl '\n'
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

int dist[110][110];
int mat[110][110];
int ans = 0;
//bool flag = false;

int dfswfloodfill(int x, int y, int r, int c){
    if(dist[x][y]) return dist[x][y];
    /*for(int i = 0; i < bt.size(); i++){
        if(bt[i] == mat[x][y] && i < ans){ // se a quantidade de elementos que faltam for menor que a resposta, retorna 0 (não é possível encontrar um caminho maior)
            cout << "bt[i] = " << bt[i] << " " <<  x << " " << y << " " << dist[x][y] << endl;
            flag = true;
            return 0;
        }
    }*/

    if(x > 0 && mat[x-1][y] < mat[x][y]){
        dist[x][y] = max(dist[x][y], dfswfloodfill(x-1, y, r, c));
    }
    if(x < r-1 && mat[x+1][y] < mat[x][y]){
        dist[x][y] = max(dist[x][y], dfswfloodfill(x+1, y, r, c));
    }
    if(y > 0 && mat[x][y-1] < mat[x][y]){
        dist[x][y] = max(dist[x][y], dfswfloodfill(x, y-1, r, c));
    }
    if(y < c-1 && mat[x][y+1] < mat[x][y]){
        dist[x][y] = max(dist[x][y], dfswfloodfill(x, y+1, r, c));
    }
    dist[x][y]++;
    return dist[x][y];
}

int main(){
    fastio;

    int t = 0;
    cin >> t;
    while(t){
        string x;
        int r, c;
        cin >> x >> r >> c;
        memset(dist, 0, sizeof(dist));
        memset(mat, 0, sizeof(mat));
        ans = 0;
        //flag = false;
        vector<int> bt;
        for(int i = 0 ; i < r;i++){
            for(int j = 0; j < c;j++){
                cin >> mat[i][j];   
                //bt.pb(mat[i][j]);
            }
        }
        //sort(bt.begin(), bt.end());
        for(int i = 0 ; i < r;i++){
            for(int j = 0; j < c;j++){
                //if(flag) break;
                ans = max(ans, dfswfloodfill(i, j, r, c));
            }
        }
        cout << x << ": " << ans << endl;
        t--;
    }

    return 0;
}