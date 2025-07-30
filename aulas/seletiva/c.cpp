#include <bits/stdc++.h>
using namespace std;

int main(){
    int q, k , d, v;
    int resp = 0,cont = 0, div = 0;
    cin >> q >> k >> d >> v;
    while(cont < k){
        int quart = 1;
        resp++;
        while(div < d && quart < q){
            div++;
            if(quart+1 <= q)quart+=1;
            else break;
        }
        cont += v*quart;
    }
    cout << resp << endl;

    return 0;
}