#include <bits/stdc++.h>
using namespace std;



int main(){
    long long n, m, a;
    cin >> n >> m >> a;
    long long cont1 = 0, cont2 = 0;
    while (n > 0){
        n -= a; // quantidade de quadrados que cabem nas linhas (perimetro)
        cont1++;
    }
    while (m > 0){
        m -= a; // quantidade de quadrados que cabem nas colunas (perimetro)
        cont2++;
    }
    long long total = cont1 * cont2; // quantidade total de quadrados necessários para preencher a area
    cout << total << endl;
}