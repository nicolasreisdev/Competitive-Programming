#include <bits/stdc++.h>
using namespace std;

int main(){
    long long x, y;cin >> x >> y;
    while (x != 0 || y != 0){
        int cont = 0;
        if (x == 0 && y == 0)
            break;
        else{
            int carry = 0;
            while (x != 0 || y != 0){
                if (x % 10 + y % 10 + carry >= 10){
                    cont++;
                    carry = 1;
                }
                else carry = 0;
                x /= 10;
                y /= 10;
            }
        }
        if (cont == 0) cout << "No carry operation.\n";
        else if (cont == 1) cout << cont << " carry operation.\n";
        else cout << cont << " carry operations.\n";
        cin >> x >> y;
    }
    return 0;
}