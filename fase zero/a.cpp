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
bitset<10000010> bs;
vector<int> primos;   // lista de primos

void crivo(){
    _tam_crivo = 10000010; // tamanho maximo de 10 ^ 7
    bs.reset();
    bs.flip(); // todos valendo true
    bs.set(0, false);
    bs.set(1, false);                                      // exceto indices 0 e 1
    for (long long int i = 2; i <= sqrt(_tam_crivo); i++){ // para i de 2 até a raiz de _tam_crivo
        if (bs.test((size_t)i)){ // se i é primo
            for (long long int j = i * i; j <= _tam_crivo; j += i){ // marcar todos os múltiplos de i como compostos
                bs.set((size_t)j, false);
            }
            primos.push_back((int)i); // guardar o primo
        }
    }
}

bool eh_primo(ll N){ // metodo rapido para teste de primalidade
    if (N < _tam_crivo)
        return bs.test(N);// O(1)
    for (int i = 0; i < primos.size(); i++)
        if (N % primos[i] == 0)
            return false;
    return true;
}
    
void solve(ll n){   
    ll size = n/2; 
    bool flag = false;
    for(ll i = size; i >= 0;i--){
        if (eh_primo(i) == false && eh_primo(n-i) == false){
            cout << i << " " << n-i << endl;
            flag = true;
            break;
        }
    }
    if(!flag) cout << -1 << endl;
}

int main(){
    crivo();
    int t; cin >> t;
    while(t--){
        ll n; cin >> n;
        solve(n);
    }
    return 0;
}