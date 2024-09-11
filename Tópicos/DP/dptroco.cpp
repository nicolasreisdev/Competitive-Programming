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

vector<int> moedas; // moedas disponíveis
bool ok[MAX]; 
bool dp[MAX]; // valor do estado

bool solve(ll i){
    if(i == 0) return true;
    if(i < 0) return false;

    if(!ok[i]){
        dp[i] = false;
    }

    for(int j = 0; j < 6; j++){
        if(solve(i - moedas[j])){
            dp[i] = true;
            break;
        }
    }

    return dp[i];
    
}


ll solve(int k, int n){
    dp[0] = true;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < k; j++){
            if(j + moedas[i] <= k && dp[j]){
                dp[j + moedas[i]] = true;
            }
        }
    }
}

int dp[MAX];

ll solve(int k, int n){
    dp[0] = true;

    for (int i = 0; i < n; i++){
        for (int j = k-1; j >= 0; j--){
            if (j + moedas[i] <= k){
                dp[j + moedas[i]] += dp[j];
            }   
        }
    }
}


int main(){
    int n; cin >> n;
    return 0;
}