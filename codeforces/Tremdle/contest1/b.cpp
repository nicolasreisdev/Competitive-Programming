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
const int N = 1e6 + 10;

vector<int> v = {1, 2, 3, 4, 5};
int dp[N];

int main(){
    fastio;

    int n; cin >> n;

    for(int i = 0; i < 5;i++){
        for(int j = 0; j < n;j++){
            if(j + v[i] <= n && dp[j]){
                dp[j + v[i]] = true;
            }
        }
    }




    return 0;
}