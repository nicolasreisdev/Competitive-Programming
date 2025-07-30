/*
Top Down DP
guardamos a resposta de cada estado em um vetor de memoização
buscamos a resposta de um estado, se ela já foi calculada, retornamos ela
caso contrário, calculamos ela e a retornamos
Fazemos isso para todos os estados possíveis
*/


#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define endl '\n'
#define pb push_back
#define rm pop_back
#define f first
#define s second
#define sz size
#define in insert

typedef pair<int, int> p;
typedef long long ll;
const int INF  = 0x3f3f3f3f;
const ll LMAX = 0x3f3f3f3f3f3f3f3f;
const int MAX = 1e5+10;
int n, k;
vector<int> h;
int dp[MAX];

int solve(int x){
    if(x == 0) return 0;
    if(dp[x] != -1) return dp[x];

    int ans = INF;
    for(int i = max(0, x-k); i < x; i++){ // i < x because we can't jump to the same stone
        ans = min(ans, solve(i) + abs(h[x] - h[i])); // retorna o minimo entre a resposta atual e a resposta do estado anterior + a diferença de altura entre as pedras
    }

    return dp[x] = ans; // retorna a resposta do estado atual
}

int main(){
    fastio;

    cin >> n >> k;
    h.resize(n);
    for(int& i: h) cin >> i;

    memset(dp, -1, sizeof(dp));

    cout << solve(n-1) << endl;

    return 0;
}