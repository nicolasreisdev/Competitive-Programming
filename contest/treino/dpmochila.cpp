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

bool ok[MAX][MAX];
int dp[MAX][MAX];
int w[MAX], v[MAX];

int solve(int i , int j){
    if(i == 0 || j == 0) return 0; // base case
    if(!ok[i][j]){ // if the value is not calculated yet
        dp[i][j] = max(solve(i-1, j), solve(i-1, j-w[i]) + v[i]); // calculate the value
        ok[i][j] = 1; // mark as calculated
    }   
    return dp[i][j]; // return the value
}

int main(){


    return 0;
}