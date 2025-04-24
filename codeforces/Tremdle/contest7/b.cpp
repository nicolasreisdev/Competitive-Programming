#include <bits/stdc++.h>

using namespace std;

#define _                         \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);
#define int long long

typedef long long ll;

const int INF = 1e9;
const ll LINF = 1e18;

// Porém, está calor, e a cada minuto que passa você sente mais desconforto.Você tenta focar, mas não consegue.A cada minuto, passa um pernilongo próximo ao seu ouvido.De repente, você olha para a frente e percebe que o professor de Pesquisa Operacional deixou diversos inteiros escritos no quadro.Você percebe que cada inteiro de l até r, inclusive, está escrito no quadro exatamente uma vez.

//                                                                                                                                                                                                                                                                                                                                                             É a oportunidade perfeita para procrastinar.Você se propõe um desafio : em um passo,
//     você pode escolher dois números a
//             e b
//                 no quadro tais que sua semi -
//         soma a + b2 seja um inteiro,
//     apagá - los e escrever a semi - soma no quadro no lugar deles.

//                                     Você se pergunta : após zero ou mais passos,
//     podemos obter um quadro com um único número nele ? Se sim, qual é o número máximo possível que pode ser o único número restante no quadro ?

void solve(){
    int l, r;
    cin >> l >> r;
    if (l == r)
        cout << l << endl;
    else if (l + 1 == r)
        cout << -1 << endl;
    else
        cout << r - 1 << endl;
}

int32_t main(){
    _ int t = 1;
    while (t--)
        solve();
}