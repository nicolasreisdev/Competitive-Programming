#include <bits/stdc++.h>
using namespace std;


int main(){
    int n; cin >> n;
    int c, p;
    while(n != 0){
        bool enc = false;
        int v[n] = {0};
        bool x[n] = {false};
        for(int i = 0; i < n;i++){
            cin >> c >> p;
            if(p > n || p <= (n*(-1)) || i+p >= n || i+p < 0 || x[i+p] || enc){
                enc = true;
            }
            else{
                v[i+p] = c;
                x[i+p] = true;
            }
        }
        if(!enc){
            for(int i = 0; i < n-1;i++)
                cout << v[i] << " ";
            cout << v[n-1];
        }

        else cout << "-1";
        cout << endl;
        cin >> n;
    }



    return 0;
}