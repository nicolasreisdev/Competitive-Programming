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

int n, w;
vector<int> weight, value;

ll dp[110][100010];

ll solve(int item, int cap){
    if(cap < 0) return -LMAX; // if the capacity is negative, return a very negative number
    if(item == n) return 0; // if we have no more items to put in the knapsack, return 0
    if(dp[item][cap] != -1) return dp[item][cap];

    return dp[item][cap] = max(solve(item+1, cap), solve(item + 1, cap - weight[item]) + value[item]);
    // retorna o maximo entre colocar o item no knapsack e nao colocar
    // solve(item+1, cap) -> nao colocar o item no knapsack
    // solve(item + 1, cap - weight[item]) + value[item] -> colocar o item no knapsack
}



int main(){
    fastio;
    cin >> n >> w;
    weight.resize(n);
    value.resize(n);
    for(int i = 0; i < n; i++){
        cin >> weight[i] >> value[i];
    }
    memset(dp, -1, sizeof(dp)); // inicializa o vetor dp com -1

    cout << solve(0,w) << endl;

    return 0;
}