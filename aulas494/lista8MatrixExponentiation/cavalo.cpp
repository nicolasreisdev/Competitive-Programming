#include <bits/stdc++.h>
using namespace std;

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define endl '\n'
#define pb push_back
#define rm pop_back
#define f first
#define s second
#define sz size
#define in insert

typedef pair<int, int> p;
typedef unsigned int uint;
typedef long long ll;
const int MAX = 0x3f3f3f3f;
const ll LMAX = 0x3f3f3f3f3f3f3f3f;

ll mod = 4294967296;

vector<vector<uint>> matMul(vector<vector<uint>> &matA, vector<vector<uint>> &matB, int n){
    vector<vector<uint>> ans(n, vector<uint>(n));
    int k;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (ans[i][j] = k = 0; k < n; k++)
            {
                ll help = (matA[i][k] * matB[k][j]) % mod;
                ans[i][j] = (ans[i][j] + help)%mod;
            }
        }
    }

    return ans;
}

vector<vector<uint>> matPow(vector<vector<uint>> &mat, ll p, int n)
{
    vector<vector<uint>> ans(n, vector<uint>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            ans[i][j] = (i == j);

    while (p)
    {
        if (p & 1)
            ans = matMul(ans, mat, n);
        mat = matMul(mat, mat, n);
        p >>= 1;
    }

    return ans;
}

int main(){
    fastio;
    ll k; cin >> k;
    vector<vector<uint>> mat(65, vector<uint>(65));
    vector<int> dx = {1, 1, -1, -1, 2, 2, -2, -2};
    vector<int> dy = {2, -2, 2, -2, 1, -1, 1, -1};
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8;j++){
            int cel = 8*i + j;
            for(int l = 0; l < 8;l++){
                int nx = i+dx[l];
                int ny = j+ dy[l];
                if(nx < 0 || ny < 0 || nx >= 8 || ny >= 8) continue;
                int newCel = nx*8+ny;
                mat[cel][newCel] = 1; 
            }
        }
    }

    for(int i = 0; i < 65;i++) mat[64][i] = 1;

    vector<vector<uint>> ans = matPow(mat, k+1, 65);

    cout << ans[64][0] << endl;

    return 0;
}