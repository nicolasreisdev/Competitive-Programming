#include <bits/stdc++.h>

using namespace std;


#define fastio ios_base::sync_with_stdio(0); cin.tie(0);
#define endl '\n'

typedef long long ll;

int main(){

    int n; cin >> n;
    bool flag = true;
    for(int i = 0; i < n;i++){
        int x; cin >> x;
        if(x == 1) flag=false;
    }
    if(flag) cout << "EASY" << endl;
    else cout << "HARD" << endl;

    return 0;
}