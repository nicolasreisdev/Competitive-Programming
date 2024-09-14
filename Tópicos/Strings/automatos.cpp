#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define endl '\n'
#define pb push_back
#define rm pop_back
#define f first
//#define s second
#define sz size
#define in insert

typedef pair<int, int> p;
typedef long long ll;
const int MAX = 0x3f3f3f3f;
const ll LMAX = 0x3f3f3f3f3f3f3f3f;

/*
Automatos são uma forma de representar um conjunto de strings.
O automato é uma estrutura de dados que permite realizar buscas de strings em tempo linear.
O automato é uma generalização do KMP.
*/

/*
Implementações CP-Algorithms
*/

vector<int> prefix_function(string &s){
    int n = s.size();  // tamanho da string
    vector<int> pi(n); // vetor que armazenará o tamanho do maior prefixo que é sufixo
    for (int i = 1; i < n; i++){ // percorre a string
        int j = pi[i - 1]; // j é o tamanho do prefixo que é sufixo do caractere anterior
        while (j > 0 && s[i] != s[j]){ // enquanto j for maior que 0 e os caracteres forem diferentes
            j = pi[j - 1]; // j é igual ao tamanho do prefixo que é sufixo do caractere anterior
        }
        if (s[i] == s[j]){ // se os caracteres forem iguais
            j++; // aumenta o tamanho do prefixo que é sufixo
        }
        pi[i] = j; // o tamanho do prefixo que é sufixo é igual a j
    }
    return pi; // retorna o vetor com o tamanho do maior prefixo que é sufixo
}

void compute_automaton(string s, vector<vector<int>> &aut){ // s é a string, aut é o automato
    s += '#'; // adiciona um caractere especial
    int n = s.size(); // tamanho da string
    vector<int> pi = prefix_function(s); // chama a função que calcula o vetor pi
    aut.assign(n, vector<int>(26)); // inicializa o automato com 26 posições
    for (int i = 0; i < n; i++){ // percorre a string
        for (int c = 0; c < 26; c++){ // percorre o alfabeto
            int j = i; // j é igual a i
            while (j > 0 && 'a' + c != s[j]) // enquanto j for maior que 0 e os caracteres forem diferentes
                j = pi[j - 1]; // j é igual ao valor do prefixo do caractere anterior
            if ('a' + c == s[j]) // se os caracteres forem iguais
                j++; // avança para o próximo caractere
            aut[i][c] = j; // o valor do automato é igual a j
        }
    }
}

void compute_automaton(string s, vector<vector<int>> &aut){ // s é a string, aut é o automato
    s += '#'; // adiciona um caractere especial
    int n = s.size(); // tamanho da string
    vector<int> pi = prefix_function(s); // chama a função que calcula o vetor pi
    aut.assign(n, vector<int>(26)); // inicializa o automato com 26 posições
    for (int i = 0; i < n; i++){ // percorre a string
        for (int c = 0; c < 26; c++){ // percorre o alfabeto
            if (i > 0 && 'a' + c != s[i]) // se i for maior que 0 e os caracteres forem diferentes
                aut[i][c] = aut[pi[i - 1]][c]; // o valor do automato é igual ao valor do automato do caractere anterior
            else 
                aut[i][c] = i + ('a' + c == s[i]); // o valor do automato é igual a i + 1 se os caracteres forem iguais
        }
    }
}

int main(){
    fastio;

    return 0;
}