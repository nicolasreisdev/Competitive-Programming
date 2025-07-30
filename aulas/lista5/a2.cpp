#include <iostream>
#include <algorithm>
using namespace std;

// se possivel, fazer calculos com valores parciais e passar para funcao nas chamadas
// Exemplo: se tem que somar os elementos --> ao marcar true, some e passe recursivamente
// Isso evita ter que varrer o array todo ao chegar em k = n

void geraSub(bool c[], int v[], int k, int n){
    // se nao for possivel podar: entrada proxima a 30 --> TLE
    if (k == n){ // se terminou de gerar um subconjunto
        int verific = 0, out = 0;
        for (int i = 0; i < n; i++){
            if (!c[i]){
                verific++;
            }
            if (n - verific < 6)return; // se nao tiver pelo menos 6 elementos, nao imprime
        }
        if (n - verific > 6)return; // se tiver mais de 6 elementos, nao imprime
        for (int i = 0; i < n; i++){
            if(out == 5 && c[i]){
                cout << v[i] << "\n";
            }
            else if(c[i]){
                out++;
                cout << v[i] << " ";
            }
        }
        return;
    }

    c[k] = true; // subconjuntos com o elemento k
    geraSub(c, v, k + 1, n);
    c[k] = false; // subconjuntos sem o elemento k
    geraSub(c, v, k + 1, n);
}

int main(){
    bool c[1000]; // subconjunto parcial
    int v[1000];  // elementos
    int n;
    cin >> n;
    while (n != 0){
        for (int i = 0; i < n; i++)
            cin >> v[i];
        geraSub(c, v, 0, n);
        cin >> n;
        if(n!=0)cout << endl;
    }
}
