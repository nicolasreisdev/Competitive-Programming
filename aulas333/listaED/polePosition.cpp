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

    int n;
    while(cin >> n && n!=0){
        vector<int> v(n);
        bool flag = false;
        for(int i = 0; i < n;i++){
            int c, p; cin >> c >> p;
            if (p > n or p <= (n * (-1)) or i + p >= n or i + p < 0 or v[i + p] != 0){
                flag = true;
            }
            else v[i+p] = c;
        }
        if(!flag){
            for(int i = 0; i < n-1; i++) cout << v[i] << " ";
            cout << v[n-1];
        }
        else cout << -1;
        cout << endl;
    }

    return 0;
}