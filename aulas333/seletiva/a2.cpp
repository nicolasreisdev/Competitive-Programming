#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, x, a = 1;
    cin >> n;
    vector<int> v(n+1);
    map<int, int> m;
    bool s[n + 1];

    for (int i = 1; i <= n; i++){
        cin >> v[i];
    }
    for (int i = 1; i <= n; i++){
        if(m.find(v[i]) == m.end()){
            m[v[i]] = v[i + 1];
        }
    }
    for(int i = 1; i <= n; i++){
        if (m[i] == 0){
            m[i] = v[1];
        }
    }
    while(a<=n){
        x = m[a];
        for(int i = 1; i <= n; i++){
            s[i] = false;
        }
        s[a] = true;
        for(;;){
            if(s[x]){
                cout << x << " ";
                break;
            }
            s[x] = true;
            //cout << x << " ";
            x = m[x];
        }
        a++;
    }
    cout << endl;

    return 0;
}