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
const int MAX = 0x3f3f3f3f;
const ll LMAX = 0x3f3f3f3f3f3f3f3f;

// GULOSO PARA MAIOR INTERVALO POSSIVEL 
void solve1(){

    int n, t, sum = 0, ans = 0;
    cin >> n >> t;// n = quantidade de livros, t = tempo
    queue<int> pq;
    for (int i = 0; i < n; i++){
        int x;
        cin >> x; // x é o tempo de leitura do livro
        pq.push(x);
        sum += x; // soma os elementos
        if (sum > t){ // se a soma for maior que o t, isto é, ela não cabe no intervalo
            sum -= pq.front(); // decrementa o primeiro elemento
            pq.pop(); // remove o primeiro elemento
        }
        ans = max(ans, (int)pq.size()); // atualiza a resposta de acordo com o maior intervalo (maior quantidade de livros possivel)
    }
    cout << ans << endl; // imprime o maior intervalo

    /*
    input:
    4 5
    3 1 2 1

    output:
    3

    input:
    3 3
    2 2 3

    output:
    1

    */
}

// GULOSO PARA MAIOR SOMA POSSIVEL
void solve2(){
    int n; cin >> n;
    vector<int> v;
    for(int i = 0; i < n;i++){
        int x; cin >> x;
        v.push_back(x);
    }
    int ans =-MAX, sum_last = -MAX;
    for(int i = 0; i < n;i++){
        if(sum_last < 0)sum_last = 0; // se a soma for menor que 0, atualiza a soma
        sum_last += v[i]; // soma os elementos
        ans = max(ans, sum_last); // atualiza a resposta de acordo com a maior soma possivel
    }
    cout << ans << endl; // imprime a maior soma possivel

/*
input: 
7
-2 5 -1 8 -11 7 3

output:
12

input: 
10
50 42 -35 2 -60 5 30 -1 40 31

output:
105

*/

}



int main(){
    solve1();
    solve2();
    return 0;
}