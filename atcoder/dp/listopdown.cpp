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

int dp[LMAX]; // vetor de memoização
string a; // string de entrada
int lisMax = 0; // variável que armazena o maior valor da LIS

int LIS(int i){
    if (dp[i] != -1)return dp[i];
    
    dp[i] = 1; // inicializa o valor de dp[i] como 1 (pois o menor valor de subsequencia é 1)
    for (int j = 0; j <= i; j++) // percorre todos os elementos anteriores a i (possiveis subsequencias)
        if(a[j] <= a[i]) // se o elemento j for menor ou igual ao elemento i
            dp[i] = max(dp[i], LIS(j) + 1); // atualiza o valor de dp[i] com o maior valor entre o valor atual e o valor da subsequencia de j + 1

    lisMax = max(lisMax, dp[i]); // atualiza o valor da maior subsequencia

    return dp[i]; // retorna o valor da subsequencia
}





int main(){
    fastio;

    string x; cin >> x;
    memset(dp, -1, sizeof(dp));
    dp[0] = 1;
    //int ans =  LIS()


    return 0;
}