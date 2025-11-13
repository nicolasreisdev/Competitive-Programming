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

ll mod = 1e9 + 7;

vector<vector<ll>> matMul(vector<vector<ll>> &matA, vector<vector<ll>> &matB, int n)
{
    vector<vector<ll>> ans(n, vector<ll>(n, 0));
    int k;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (ans[i][j] = k = 0; k < n; k++)
            {
                ll help = (matA[i][k] * matB[k][j]) % mod;
                ans[i][j] = (ans[i][j] + help) % mod; 
            }
        }
    }

    return ans;
}

vector<vector<ll>> matPow(vector<vector<ll>> &mat, ll p, int n)
{
    vector<vector<ll>> ans (n, vector<ll>(n, 0));
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
    ll n, k; cin >> n >> k;
    vector<ll> v(n);
    for(int i = 0; i < n;i++) cin >> v[i];

    vector<vector<ll>> mat(n, vector<ll>(n, 0));

    for(int i = 0; i < n;i++){
        for(int j = 0; j < n;j++){
            
            ll xorValue = v[i] ^ v[j];
            bitset<64> aux(xorValue);

            if(aux.count() % 3 == 0) mat[i][j] = 1;
        }
    }

    vector<vector<ll>> matAns = matPow(mat, k-1, n);

    ll ans = 0;
    for(int i = 0; i < n;i++){
        for(int j = 0; j < n;j++){
            ans = (ans+matAns[i][j])%mod;
        }
    }

    cout << ans << endl;


    return 0;
}