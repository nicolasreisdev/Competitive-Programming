#include <bits/stdc++.h>
using namespace std;

long long int _tam_crivo;
long long int primes[10000010];

void crivo()
{
    _tam_crivo = 1000000 + 10;
    memset(primes, 1, sizeof(primes)); // 1 = primo, 0 = composto
    primes[0] = 0;                     // 0 não é primo
    for (long long int i = 2; i <= sqrt(_tam_crivo); i++)
    { // para i de 2 até a raiz de _tam_crivo
        if (primes[i])
        { // se i é primo
            for (long long int j = i * i; j <= _tam_crivo; j += i)
            { // marcar todos os múltiplos de i como compostos
                primes[j] = 0;
            }
        }
    }
}

void Goldbach(int n)
{
    for (int i = 3; i <= n / 2; i++)
    { // i <= n/2
        if (primes[i] && primes[n - i])
        { // i+n-i = n
            cout << n << " = " << i << " + " << n - i << endl;
            return;
        }
    }
}

int main()
{
    crivo(); // gerar crivo
    int n;
    cin >> n;
    while (n != 0)
    {
        Goldbach(n);
        cin >> n;
    }

    return 0;
}