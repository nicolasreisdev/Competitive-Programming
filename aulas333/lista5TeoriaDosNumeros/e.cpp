#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll _tam_crivo;
bitset<1010> bs; // 10^7 + extra bits, suficiente para maioria
vector<int> primos;   // lista de primos

void crivo(ll limite){// cria lista de primos em [0..limite]
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
bool eh_primo(ll N){
    if (N < _tam_crivo)
        return bs.test(N);
    for (int i = 0; i < primos.size(); i++)
        if (N % primos[i] == 0)
            return false;
    return true;
}
    // se possivel, fazer calculos com valores parciais e passar para funcao nas chamadas
    // Isso evita ter que varrer o array todo ao chegar em k = n
    void geraPerm(bool usei[], int perm[], int k, int n){
        // se nao for possivel podar: entrada proxima a 13 --> TLE

        if (k == n+1){ // se terminou de gerar uma permutacao
            bool flag = true;
            if(perm[1] != 1) return;
            for (int i = 2; i <= n; i++){
                if(i == n)if(!eh_primo(perm[i]+perm[1])) flag = false;
                if(!eh_primo(perm[i]+perm[i-1])) flag = false;
            }   
            if(flag){
                for (int i = 1; i <= n; i++){
                    if(i!=n)cout << perm[i] << " ";
                    else cout << perm[i];
                }
                cout<< endl;
            }
            return;
        }

        for (int i = 2; i <= n; i++){
            if (!usei[i] && eh_primo(i+perm[k-1])){
                usei[i] = true;
                perm[k] = i;
                geraPerm(usei, perm, k + 1, n);
                usei[i] = false; // ATENCAO!
            }
        }
    }

int main(){
    crivo(50);
    int n, caso = 1;
    cin >> n;
    while(true){
        int perm[1001]; // permutacao parcial
        bool usei[1001] = {false};
        memset(perm, 0, sizeof(perm));
        perm[1] = 1;
        cout << "Case " << caso << ":" << endl;
        geraPerm(usei, perm, 2, n); // permutacoes de [0, 1, 2, 3, ..., n-1]
        caso++;
        if(!(cin >> n)) break;
        cout << endl;
    }
    return 0;
}
