#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, k,x, cont =0, num;
    cin >> n >> k;
    for(int i = 0; i < n; i++){
        cin >> x;
        if(x>0 && i<k-1) cont++;
        if(i==k-1) num = x;
        if(x>0 && i>=k-1 && x==num) cont++;
    }
    cout << cont << endl;


    return 0;
}