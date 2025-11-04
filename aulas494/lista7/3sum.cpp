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

int main(){
    fastio;

    int n, x; cin >> n >> x;
    vector<p> v; // f = value, s = index
    for(int i = 1; i <= n;i++){
        int x; cin >> x;
        v.pb({x, i});
    }

    sort(v.begin(), v.end());

    for(int i = 0; i < v.size();i++){
        int value = v[i].f;
        int l = 0, r = n-1;
        while(l != r){
            int target = x - value;
            if(l != i and r != i and v[l].f + v[r].f == target){
                cout << v[i].s << " " << v[l].s << " " << v[r].s << endl;
                return 0;
            }
            if (v[l].f + v[r].f < target) l++;
            else r--;
        }
    }

    cout << "IMPOSSIBLE" << endl;


    return 0;
}