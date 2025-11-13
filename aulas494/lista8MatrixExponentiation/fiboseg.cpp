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
typedef long long ll;
const int MAX = 0x3f3f3f3f;
const ll LMAX = 0x3f3f3f3f3f3f3f3f;

vector<vector<ll>> matMul(vector<vector<ll>> &matA, vector<vector<ll>> &matB, int n)
{
    vector<vector<ll>> ans(n, vector<ll>(n));
    int k;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (ans[i][j] = k = 0; k < n; k++)
            {
                ans[i][j] += matA[i][k] * matB[k][j];
            }
        }
    }

    return ans;
}

vector<vector<ll>> matPow(vector<vector<ll>> &mat, int p, int n){
    vector<vector<ll>> ans(n, vector<ll>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            ans[i][j] = (i == j);

    while (p){
        if (p & 1)
            ans = matMul(ans, mat, n);
        mat = matMul(mat, mat, n);
        p >>= 1;
    }


    return ans;
}

int main(){
    fastio;

    int n, m; cin >> n >> m;
    vector<ll> v(n);
    for(int i = 0; i < n;i++) cin >> v[i];

    while(m--){
        ll tp, l, r; cin >> tp >> l >> r;
        if(tp == 1){
            ll x; cin >> x;

        }
        else{
            
        }
    }
    return 0;
}