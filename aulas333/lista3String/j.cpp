#include <bits/stdc++.h>
using namespace std;


int main(){
    string a, b;cin >> a >> b;
    while(a!="0" || b!="0"){
        int n, cont = 0;
        a = "0" + a;
        b = "0" + b;
        if(a.size() > b.size())n = a.size();
        else n = b.size();
        while(a.size() < n){
            a = "0" + a;
        }
        while(b.size() < n){
            b = "0" + b;
        }
        long int carry = 0;
        for(int i = n-1; i >= 0;i--){
            int x,y;
            x = a[i] - '0'; 
            y = b[i] - '0';
            if((x+y+carry) > 9){
                cont++;
                carry = 1;
            }
            else carry = 0;
        }
        if(cont == 0) cout << "No carry operation." << endl;
        else if(cont == 1) cout << cont << " carry operation." << endl;
        else cout << cont << " carry operations." << endl;
        cin >> a >> b;
    }   


    return 0;
}