#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define endl '\n'
#define pb push_back
#define rm pop_back
#define f first
//#define s second
#define sz size
#define in insert

typedef pair<int, int> p;
typedef long long ll;
const int MAX = 0x3f3f3f3f;
const ll LMAX = 0x3f3f3f3f3f3f3f3f;

int main(){
    fastio;

    int t, c = 1; cin >> t;
    while(t){
        int n, d, q = 2; cin >> n >> d;
        vector<int> v(1e3);
        v[0] = v[1] = 0;

        for(int i = 0; i < n;i++){
            char ignore, l;
            int s;
            cin >> l;cin >> ignore;cin >> s;
            if(l == 'B'){
                v[q] = s;
                v[q+1] = s;
                q+=2;
            }
            else{
                v[q] = s;
                q++;
            }
        }
        v[q] = d;
        v[q+1] = d;
        q++;
        int dist = 0;
        int val;
        for(val = 2; val < q; val+=2){
            dist = max(dist, v[val] - v[val-2]);
        }
        val-=1;
        for(val; val>=2; val-=2){
            dist = max(dist, v[val] - v[val-2]);
        }

        cout << "Case " << c << ": " << dist << endl;
        c++;
        t--;
    }
    return 0;
}