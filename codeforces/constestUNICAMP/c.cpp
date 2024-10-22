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

int main(){
    fastio;

    int n, k; cin >> n >> k;
    vector<int>v(n+2, 0);
    for(int i = 1; i <= n;i++) cin >> v[i];
    int maiorinter = -1, menorinter = -1;
    ll prefixsum = 0, maxans = 0, minans = MAX;
    for(int i = 1; i <= n; i++){
        prefixsum+=v[i];
        if(i >= k){
            prefixsum-=v[i-k];
            if(prefixsum > maxans)maxans = prefixsum, maiorinter = i-k+1;
            if(prefixsum < minans)minans = prefixsum, menorinter = i-k+1;
        }
    }
    cout << menorinter << " " << maiorinter;
    

    return 0;
}