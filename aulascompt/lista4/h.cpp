#include <bits/stdc++.h>
using namespace std;

long long int _tam_crivo;
long long int primes[1000000010];
vector<int>nprime(1000000010, 0);


void crivo(){
    _tam_crivo = 1000000000 + 10;
    memset(primes, 1, sizeof(primes));
    primes[0] = 0;
    for (long long int i = 2; i <= sqrt(_tam_crivo); i++){
        if (primes[i]){
            for (long long int j = i * i; j <= _tam_crivo; j += i){
                primes[j] = 0;
                nprime[j]++;
            }
        }
    }
}

void isprime(int x, int y){
    int maior = 0, number;
    for(int i = x; i < y; i++){
        if(nprime[i] > maior){
            maior = nprime[i];
            number = i;
        }
    }
    cout << "Between " << x << " and " << y << ", " << number << " has a maximum of " << maior << " divisors." << endl;
}

int main()
{
    int n;
    cin >> n;
    for(int i = 0; i < n;i++){
        int x, y; cin >> x >> y;
        isprime(x, y);
    }

    return 0;
}