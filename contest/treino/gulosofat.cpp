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
const int MAX = 1e5 + 10;
const int MIN = 0;


//MENOR QUANTIDADE DE FATORIAL PARA FORMAR UM NUMERO
int main(){
    int n;cin >> n;
    int ans = 0;
    vector<int> fat(11);  
    fat[0] = 1; 
    for(int i = 1; i <= 10;i++)fat[i] = fat[i-1]*i; //fatorial de 0 a 10 (> 1e6)

    for(int i = 10; i >= 1; i--){
        ans += n/fat[i]; //divisao inteira (verifica se o fatorial cabe no numero, se couber, incrementa o ans)
        n %= fat[i]; //resto (se couber, pega o resto da divisao inteira)
    }
    cout << ans << endl;

    return 0;
}