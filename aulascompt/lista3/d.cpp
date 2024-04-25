#include <bits/stdc++.h>
using namespace std;

int main(){
    long int n, m; cin >> n;
    vector<int>v(10);
    string x;
    for(int i = 0; i < n;i++){
        cin >> m;
        for(int j = 1; j <= m;j++){
            x += to_string(j);
        }
        for(int j = 0; j < x.size();j++){
            v[x[j]-'0']++;
        }
        for(int j = 0; j < 10;j++){
            if(j == 9) cout << v[j] << endl;
            else cout << v[j] << " ";
            v[j] = 0;
        }
        x.clear();
    }


    return 0;
}