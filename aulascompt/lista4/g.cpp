#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, k;
    while(cin >> n >> k){
        int cig = n, qntd = n;
        while(cig >= k){
            qntd += cig/k;
            cig = cig/k + cig%k;
        }
        cout << qntd << endl;
    }
    return 0;
}
