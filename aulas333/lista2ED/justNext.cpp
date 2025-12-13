#include <bits/stdc++.h>
using namespace std;   

int main(){
    int n, m; cin >> n;
    for(int i = 0; i < n;i++){
        cin >> m;
        string x, t;
        for (int j = 0; j < m; j++){
            cin >> x;
            t+=x;
        }
        if(next_permutation(t.begin(), t.end()))cout << t << endl;
        else cout << "-1" << endl;
        x.clear();t.clear();
    }


    return 0;
}