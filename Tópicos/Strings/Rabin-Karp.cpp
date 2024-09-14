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

/*
Rabin Karp é um algoritmo que encontra todas as ocorrências de um padrão em um texto.
O algoritmo é baseado em uma função de hash que calcula o hash do padrão e do texto.
O algoritmo percorre o texto e o padrão ao mesmo tempo, se os hashes forem iguais, compara os caracteres.
Se o padrão for encontrado, adiciona a posição do texto onde o padrão foi encontrado.
O algoritmo tem complexidade O(n + m), onde n é o tamanho do texto e m é o tamanho do padrão.
*/

/*
Implementação CP-Algorithms
*/

vector<int> rabin_karp(string const &s, string const &t){ // s é o padrão, t é o texto
    const int p = 31; // primo
    const int m = 1e9 + 9; // módulo
    int S = s.size(), T = t.size(); // tamanho do padrão e do texto

    vector<long long> p_pow(max(S, T)); // vetor que armazenará as potências de p
    p_pow[0] = 1; // a primeira potência de p é 1
    for (int i = 1; i < (int)p_pow.size(); i++) // percorre o vetor
        p_pow[i] = (p_pow[i - 1] * p) % m; // calcula a potência de p

    vector<long long> h(T + 1, 0); // vetor que armazenará o hash do texto
    for (int i = 0; i < T; i++) // percorre o texto
        h[i + 1] = (h[i] + (t[i] - 'a' + 1) * p_pow[i]) % m; // calcula o hash do texto
    long long h_s = 0; // hash do padrão
    for (int i = 0; i < S; i++) // percorre o padrão
        h_s = (h_s + (s[i] - 'a' + 1) * p_pow[i]) % m; // calcula o hash do padrão

    vector<int> occurrences; // vetor que armazenará as posições do texto onde o padrão foi encontrado
    for (int i = 0; i + S - 1 < T; i++){ // percorre o texto
        long long cur_h = (h[i + S] + m - h[i]) % m; // calcula o hash do texto
        if (cur_h == h_s * p_pow[i] % m) // se os hashes forem iguais
            occurrences.push_back(i); // adiciona a posição do texto onde o padrão foi encontrado
    }
    return occurrences; // retorna o vetor com as posições do texto onde o padrão foi encontrado
}

int main(){
    fastio;

    

    return 0;
}