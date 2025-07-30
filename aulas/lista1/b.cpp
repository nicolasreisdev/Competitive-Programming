#include <bits/stdc++.h>
using namespace std;


int main(){
    string x; cin >> x;
    int resp = 0;
    for(int i = 0; i < x.size();i++){
        string y, z;
        y = x.substr(0,i+1);
        z = y;
        reverse(y.begin(), y.end());
        if(y != z) resp = y.size();
    }
    cout << resp << "\n";



    return 0;
}