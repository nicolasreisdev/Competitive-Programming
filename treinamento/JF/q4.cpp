#include <bits/stdc++.h>
using namespace std;

int main(){
    int n; cin >> n;
    int max = (n-1)*2;
    int maxdiv, mindiv;maxdiv = mindiv = max/2;
    for(int i = 0; i < n;i++){
        for(int j = 0; j <= max;j++){
            if(j >= mindiv && j <= maxdiv) cout << "#";
            else cout << " ";
        }
        cout << "\n";
        maxdiv++;
        mindiv--;
    }




    return 0;
}