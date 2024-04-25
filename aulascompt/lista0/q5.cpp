#include <bits/stdc++.h>
using namespace std;

long long int cont = 0, maior = 0;

void collatz(long long int n){
    if(n == 1){
        cont++;
        return;
    }
    cont++;
    if(n % 2 == 1){
        collatz((3 * n) + 1);
    }else{
        collatz(n / 2);
    }
}

int main(){
    long long int c ,d,a, b;
    bool troc = true;
    while (cin >> c >> d)
    {
        troc = false;
        maior = 0;
        if(c > d){
            swap(c, d);
            troc = true;
        }
        for (long long int i = c; i <= d; i++){
            collatz(i);
            if(cont > maior) maior = cont;
            cont = 0; 
        }
        if(troc) swap(c,d);
        cout << c << " " << d << " " << maior << endl;
    }

        return 0;
    }