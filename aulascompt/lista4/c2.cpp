#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    while (n != 0){
        int resp = 1;
        while (resp <= n){
            resp *= 2;
        }
        resp = resp%n; 
        cout << (n-resp) << endl;
        cin >> n;
    }

    return 0;
}