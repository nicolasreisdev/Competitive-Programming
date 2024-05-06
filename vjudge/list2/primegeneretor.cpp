#include <bits/stdc++.h>
using namespace std;

#define ll long long
ll primes[10000010];

void crivo(){
    ll MAX = 10000010;
    memset(primes, 1, sizeof(primes));
    for(ll i = 2; i <= sqrt(MAX);i++){
        if(primes[i]){
            for(int j = i*i; j <= MAX;j+=i){
                primes[j] = 0;
            }
        }
    }
}


void printPrimes(ll m , ll n){
    for(ll i = m; i <= n;i++){
        if(primes[i]){
            cout << i << endl;
        }
    }
}

int main(){
    crivo();
    int t; cin >> t;
    while(t!=0){
        ll m , n; cin >> m >> n;
        printPrimes(m, n);
        cout << endl;
        t--;
    }


    return 0;
}