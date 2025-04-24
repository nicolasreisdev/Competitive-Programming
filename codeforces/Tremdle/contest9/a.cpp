// Vinicius não gosta de vectors, e por isso possui arrays em excesso, então ele quer deletar o menos importante deles.No entanto, ele descobriu que este array é mágico !Vinicius agora sabe que o array tem as seguintes propriedades :

//     Em um segundo,
//     podemos adicionar um inteiro arbitrário(possivelmente negativo) a todos os elementos do array que não são iguais a zero.Quando todos os elementos do array se tornam iguais a zero,
//     o array explode.Vinicius está sempre ocupado,
//     então ele quer explodir o array o mais rápido possível.Compute o tempo mínimo em que o array pode ser explodido.

// Sample:
// 5
// 1 1 1 1 1

// 4 
// 5 - 6 - 5 1

#include <bits/stdc++.h>

using namespace std;

#define _                         \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);
#define int long long

typedef long long ll;

const int INF = 1e9;
const ll LINF = 1e18;

void solve()
{

    int n;
    cin >> n;
    set<int> s;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        if (x != 0)
            s.insert(x);
    }
    cout << s.size() << endl;
}

int32_t main()
{
    _ int t = 1;
    while (t--)
        solve();
}
