#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define endl '\n'
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

void crivo(ll limite){// cria lista de primos em [0..limite]
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
bool eh_primo(ll N){
    if (N < _tam_crivo)
        return bs.test(N);
    for (int i = 0; i < primos.size(); i++)
        if (N % primos[i] == 0)
            return false;
    return true;
}

void solve(ll m, ll n){
    int minDist = (n-m), maxDist = 0;
    ll last = m, a, b, c, d;
    bool flagone = false, flagtwo = false;
    for (ll i = m+1; i <= n; i++){
        if(eh_primo(i)){
            if(i-last < minDist){
                minDist = i-last;
                a = last;
                b = i;
                flagone = true;
            }
            if(i-last > maxDist){
                maxDist = i-last;
                c = last;
                d = i;
                flagtwo = true;
            }
            last = i;
        }
    }
    if(!flagone || !flagtwo) cout << "There are no adjacent primes." << endl;
    else cout << a << "," << b << " are closest, " << c << "," << d << " are most distant." << endl;
}

int main(){
    fastio;
    crivo(100000000);
    ll m, n;
    while(cin >> m >> n){
        solve(m, n);
        cout << endl;
    }

    return 0;
}