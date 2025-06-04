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

void solve(){
    int n; cin >> n;
    deque<int> v;
    for(int i =0; i < n;i++){
        int x; cin >> x; v.push_back(x);
    }
    int value = v[0], ant;
    while(true){
        if(v[n/2-1]==value or v[n/2-1] == -value){
            cout << "Yes" << endl;
            return;
        }
        else if(v[n/2-1] > value){
            v[n/2] *= -1;
            sort(v.begin(), v.end());
        }
        else if(v[n/2-1] < value){
            value*=-1;
        }
    }
}


int main(){
    fastio;

    int t; cin >> t;
    while(t--){
        solve();
    }


    return 0;
}