#include <bits/stdc++.h>    
using namespace std;

long long int _tam_crivo;
long long int primes[10000010];

void crivo(){
    _tam_crivo = 1000000 + 10;
    memset(primes, 1, sizeof(primes));
    primes[0] = 0;
    for(long long int i = 2; i <= sqrt(_tam_crivo); i++){
        if(primes[i]){
            for(long long int j = i * i; j <= _tam_crivo; j += i){
                primes[j] = 0;
            }
        }
    }
}

void Goldbach(int n){
    for (int i = 3; i <= n/2; i++){
        if (primes[i] && primes[n-i]){ // i+n-i = n
            cout << n << " = " << i << " + " << n - i << endl;
            return;
        }
    }
    cout << "Goldbach's conjecture is wrong." << endl;
}

int main(){
    crivo();
    int n; cin >> n;
    while(n != 0){
        Goldbach(n);
        cin >> n;
    }

    return 0;
}