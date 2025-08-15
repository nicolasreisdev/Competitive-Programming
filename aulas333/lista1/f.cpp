#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,x;
    double tot = 0, resp = 0, k;
    cin >> n >> k;
    double y = n;
    for(int i = 0; i < n;i++){
        cin >> x;
        tot += x;
    }
    resp = tot/y;
    while(resp < (k-0.5)){
        y++;
        tot += k;
        resp = tot/y;
    }
    cout << (y-n) << endl;


    return 0;
}