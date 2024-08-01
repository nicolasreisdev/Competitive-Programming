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

ll _tam_crivo;
bitset<100000010> bs; // 10^7 + extra bits, suficiente para maioria
vector<int> primos;   // lista de primos

void crivo(ll limite)
{                            // cria lista de primos em [0..limite]
    _tam_crivo = limite + 1; // + 1 para incluir limite
    bs.reset();
    bs.flip(); // todos valendo true
    bs.set(0, false);
    bs.set(1, false); // exceto indices 0 e 1
    for (ll i = 2; i <= _tam_crivo; i++)
        if (bs.test((size_t)i))
        { // corta todos os multiplos de i comecando de i*i
            for (ll j = i * i; j <= _tam_crivo; j += i)
                bs.set((size_t)j, false);
            primos.push_back((int)i); // adiciona na lista de primos
        }
}
bool eh_primo(ll N)
{
    if (N < _tam_crivo)
        return bs.test(N);
    for (int i = 0; i < primos.size(); i++)
        if (N % primos[i] == 0)
            return false;
    return true;
}

vector<int> fatores(int n){
    vector<int> fatores;
    for (int i = 2; i <= sqrt(n); i++){ // para i de 2 até a raiz de n
        while (n % i == 0){ // enquanto n for divisível por i
            fatores.push_back(i); // adiciona i aos fatores
            n /= i;               // divide n por i
        }
    }
    if (n > 1)
        fatores.push_back(n); // se n for maior que 1, adiciona n aos fatores
    return fatores;
}


void solve(ll n)
{
    for(int i = n-1; i > 0;i--){
        n = n * i%n 
    }

    vector<int> ans;
    for (int i = 0; i < primos.size(); i++)
    {
        if (n % primos[i] == 0){
            ans.pb(primos[i]);
            while (n % primos[i] == 0)
            {
                n /= primos[i];
            }
            if (n == 0)
                return;
        }
    }

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
}

int main()
{
    //crivo(10000000);
    int n;
    cin >> n;
    while (n != 0)
    {
        cout << n << "! = ";
        cout << endl;
        cin >> n;
    }

    return 0;
}