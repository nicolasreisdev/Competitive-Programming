#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define rm pop_back
#define f first
#define s second

typedef pair<int, int> p;
typedef long long ll;
const int MAX = 1e5 + 10;


int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    vector<int> polen(1000010, 0);

    int n, k;
    cin >> n >> k;

    int x;
    for (int i = 0; i < n; i++){
        cin >> x;
        polen[x]++;
    }

    int soma, valor;

    for (int i = 1000009; i >= 0; i--){
        soma = 0;
        valor = i;

        while (valor){
            soma += valor % 10;
            valor /= 10;
        }

        if (polen[i] >= k){
            cout << soma << '\n';
            return 0;
        }
        else{
            k -= polen[i];
            polen[i - soma] += polen[i];
        }
    }

    cout << 0 << '\n';

    return 0;
}