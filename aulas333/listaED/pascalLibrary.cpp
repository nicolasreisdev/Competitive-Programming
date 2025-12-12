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

    int n, d;
    while (cin >> n >> d){
        vector<int> v(n);
        for(int i = 0; i < d;i++){
            for(int j = 0; j < n;j++){
                int x; cin >> x;
                v[j] += x;
            }
        }
        bool flag = false;
        for(int i = 0; i < n;i++){
            if(v[i] >= d){
                cout << "yes" << endl;
                flag = true;
                break;
            }   
        }
        if(flag) cout << "no" << endl;
    }

    return 0;
}