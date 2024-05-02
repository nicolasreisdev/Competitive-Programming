#include <bits/stdc++.h>
using namespace std;

long long int _tam_crivo;
long long int primes[10000010];

void crivo(){
    _tam_crivo = 1000000 + 10; // tamanho do crivo 1e6 + 10
    memset(primes, 1, sizeof(primes)); // 1 = primo, 0 = composto
    vector<int> primos;
    primes[0] = 0; // 0 não é primo
    for (long long int i = 2; i <= sqrt(_tam_crivo); i++){ // para i de 2 até a raiz de _tam_crivo
        if (primes[i]){ // se i é primo
            for (long long int j = i * i; j <= _tam_crivo; j += i){ // marcar todos os múltiplos de i como compostos
                primes[j] = 0;
            }
            primos.push_back(i);
        }
    }
}

int main(){
    



    return 0;
}