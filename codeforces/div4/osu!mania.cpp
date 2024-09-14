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

    int t;
    cin >> t;
    while (t--){
        int n; cin >> n;
        vector<int> pos;
        for(int i = 0; i < n;i++){
            string x; cin >> x;
            for(int i = 0; i < x.size();i++){
                if(x[i] == '#')pos.pb(i+1);
            }
        }
        for(int i = pos.size()-1;i >= 0;i--){
            cout << pos[i] << " ";
        }
        cout << endl;
    }

    return 0;
}