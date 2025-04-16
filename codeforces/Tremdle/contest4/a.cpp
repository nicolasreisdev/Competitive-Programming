#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);

typedef long long ll;



int main(){
    fastio;
    int n; cin >> n;
    vector<string> v;
    bool flag = false;
    for(int i = 0; i < n;i++){
        string c; cin >> c;
        if(c[0] == 'O' and c[1] == 'O' and !flag){
            flag = true; c[0]='+'; c[1] = '+';
        }
        else if(c[3] == 'O' and c[4]=='O' and !flag){
            flag = true;
            c[3] = '+';
            c[4] = '+';
        }
        v.push_back(c);
    }

    if(flag){
        cout << "YES" << endl;
        for(auto e:v){
            cout << e << endl;
        }
    }
    else cout << "NO" << endl;


    return 0;
}