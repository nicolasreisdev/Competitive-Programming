#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define rm pop_back
#define f first
#define s second
#define sz size
#define in insert

typedef pair<int, int> p;
typedef long long ll;
const int MAX = 0x3f3f3f3f;
const ll LMAX = 0x3f3f3f3f3f3f3f3f;

long long int _tam_crivo;
long long int primes[100010];
vector<int> primos;

void crivo(){
    _tam_crivo = 10000 + 10;
    memset(primes, 1, sizeof(primes));
    primes[0] = 0;
    primes[1] = 0;
    for (long long int i = 2; i < _tam_crivo; i++){
        if (primes[i]){
            for (long long int j = i * i; j <= _tam_crivo; j += i){
                primes[j] = 0;
            }
            primos.pb(i);
        }
    }
}

void Noldbach(int n, int k){
    int sum = 0;
    for (int i = 0; i < primos.size()-1; i++){
        if (primos[i]+primos[i+1]+1 <= n && primes[primos[i]+primos[i+1]+1])sum++;
    }
    if (sum < k)
        cout << "NO" << endl;
    else
        cout << "YES" << endl;
}

int main()
{
    crivo();
    int n, k;
    cin >> n >> k;

    Noldbach(n, k);

    return 0;
}