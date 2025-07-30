#include <bits/stdc++.h>
using namespace std;

bool verific(string x, string y){
    for(int i = 0; i < x.size();i++){
        for(int j = 0; j < y.size();j++){
            if(x[i] == y[j]){
                return true;
            }
        }
    }
    return false;
}

int main(){
    int n; cin >> n;
    string x, y;
    for(int i = 0; i < n;i++){
        cin >> x >> y;
        if(verific(x,y)) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}