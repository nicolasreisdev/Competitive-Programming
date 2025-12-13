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

int main(){
    fastio;

    ll a, b; 
    while(cin >> a >> b && a && b){
        ll win = 0;
        if(a > b) swap(a, b);
        while(a != b && b/a < 2){ // se a diferença entre a e b for maior que 2, o próximo número que o Stan escolher será maior que o dobro do número escolhido pelo Ollie 
            a = b-a; // Stan escolhe o número que é a diferença entre os dois números
            b = a; // Ollie escolhe o número que Stan escolheu
            win = 1-win; // inverte o vencedor
        }
        if(win) cout << "Ollie wins" << endl;
        else cout << "Stan wins" << endl;
    }

    return 0;
}