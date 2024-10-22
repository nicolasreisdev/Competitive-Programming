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

    int t; cin >> t;
    while(t--){
        int n, k; cin >> n >> k;
        if((n-k+1) % 2 == 0 && ((k-1)%4 == 0|| (k-1)%4 == 3)) cout << "YES" << endl;
        else if((n-k+1) % 2 == 1 && ((k-1)%4 == 2 || (k-1)%4 == 3)) cout << "YES" << endl;
        else cout << "NO" << endl;
    }


    return 0;
}