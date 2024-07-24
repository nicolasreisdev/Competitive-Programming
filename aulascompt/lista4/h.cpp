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

void crivo(ll limite){ // cria lista de primos em [0..limite]
    _tam_crivo = limite + 1; // + 1 para incluir limite
    bs.reset();
    bs.flip(); // todos valendo true
    bs.set(0, false);
    bs.set(1, false); // exceto indices 0 e 1
    for (ll i = 2; i <= _tam_crivo; i++)
        if (bs.test((size_t)i)){ // corta todos os multiplos de i comecando de i*i
            for (ll j = i * i; j <= _tam_crivo; j += i)
                bs.set((size_t)j, false);
            primos.push_back((int)i); // adiciona na lista de primos
        }
}

int eh_primo(ll N){
    //if (N < _tam_crivo)
    //    return bs.test(N);
    int ans = 1, cont = 0;
    for (int i = 0; N > 1 && i < primos.size(); i++)
        if (N % primos[i] == 0){
            cont = 1;
            while(N % primos[i] == 0){
                N /= primos[i];
                cont++;
            }
            ans *= cont;
        }

    return ans;
}

void isprime(int x, int y){
    int qntd = 0;
    ll number = 0;
    for(ll i = x; i <= y; i++){
        int aux = eh_primo(i);
        if(aux > qntd){
            qntd = aux;
            number = i;
        }
    }
    cout << "Between " << x << " and " << y << ", " << number << " has a maximum of " << qntd << " divisors." << endl;
}

int main(){
    fastio;
    crivo(1000000);

    int n;
    cin >> n;
    for(int i = 0; i < n;i++){
        int x, y; cin >> x >> y;
        isprime(x, y);
    }

    return 0;
}