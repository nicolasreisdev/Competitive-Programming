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


int main(){
    int t; cin >> t;
    while(t!=0){
        int n; cin >> n;
        int ans = 0, maxgcd = 0, y = 0;
        for(int i = 1; i < n; i++){ // i começa de 1 pois o valor de n é sempre maior que 1
            maxgcd = gcd(n, i); // pega o maior divisor comum entre n e i
            if(maxgcd+i > ans){ // se a soma do maior divisor comum com i for maior que ans (o máximo valor que pode ocorrer é n)
                ans = max(maxgcd+i, ans); // ans recebe o maior valor entre o maior divisor comum com i e ans
                y = i; // y recebe o valor de i
            }

        }
        cout << y << endl;

        t--;
    }

    /*
    input:
    7
    10
    7
    21
    100
    2
    1000
    6

    output: a saída deve ser o maximo gcd(x,y)+y possivel
    5
    6
    18
    98
    1
    750
    3

    */
    return 0;
}   