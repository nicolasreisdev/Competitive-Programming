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

// GULOSO COM INTERVALOS
/*
obter o menor numero de intervalos que cobrem todos os pontos
*/

bool cmp(p a, p b){
    return a.s < b.s;
}

int main(){
    int n;
    cin >> n;
    vector<p> v;
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        v.pb({x, y});
    }

    sort(v.begin(), v.end(), cmp); // ordena pelo segundo elemento
    int ans = 0;
    int last = -1; // menor que qualquer valor (para o primeiro caso)
    for (int i = 0; i < n; i++){
        if (v[i].f > last)
        { // se o primeiro elemento for maior que o ultimo
            ans++;
            last = v[i].s; // atualiza o ultimo
        }
    }
    cout << ans << endl;

    /*
    input:
    2
    7 11
    4 7

    output:
    1

    input:
    5
    1 2
    2 3
    3 4
    4 5
    5 6

    output:
    3

    input:
    6
    4 8
    1 5
    4 7
    2 5
    1 3
    6 8

    output:
    2

    */
    return 0;
}