#include <bits/stdc++.h>

using namespace std;

#define fastio                    \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);
#define endl '\n'

typedef long long ll;

int main(){
    fastio;
    int n, k; cin >> n >> k;
    string x; cin >> x;
    int stop = k;
    bool flag = true;
    for(int i = 0; i < x.size();i++){
        if(x[i] == '#') stop--;
        else stop = k;
        if(stop == 0) flag = false;
    }

    if(flag) cout << "YES" << endl;
    else cout << "NO" << endl;

    return 0;
}