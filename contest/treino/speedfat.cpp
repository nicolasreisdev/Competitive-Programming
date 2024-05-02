#include <bits/stdc++.h>
using namespace std;

vector<int> divisores(int n){
    vector<int> divs;
    for (int i = 1; i <= sqrt(n); i++){ // para i de 1 até a raiz de n
        if (n % i == 0){ // se n for divisível por i
            divs.push_back(i); // adiciona i aos divisores
            if (i != n / i) divs.push_back(n / i); // se i for diferente de n/i, adiciona n/i aos divisores
        }
    }
    return divs;
}

vector<int> primos(int n){
    vector<int> primos;
    for(long long div = 2; n>1;){ // n > 1
        while(n % div == 0){ // enquanto n for divisível por div
            primos.push_back(div); // adiciona o divisor
            n /= div; // divide n por div
        }
        div++;
        if(div * div > n) div = n; // se div ao quadrado for maior que n, div = n
    }
}

vector<int> fatores(int n){
    vector<int> fatores;
    for(int i = 2; i <= sqrt(n); i++){ // para i de 2 até a raiz de n
        while(n % i == 0){ // enquanto n for divisível por i
            fatores.push_back(i); // adiciona i aos fatores
            n /= i; // divide n por i
        }
    }
    if(n > 1) fatores.push_back(n); // se n for maior que 1, adiciona n aos fatores
    return fatores;
}


int main(){




    return 0;
}