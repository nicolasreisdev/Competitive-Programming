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
KMP é um algoritmo que encontra todas as ocorrências de um padrão em um texto.
O algoritmo é baseado em um vetor lps (longest prefix suffix) que armazena o tamanho do maior prefixo que é sufixo.
O vetor lps é calculado a partir do padrão.
O algoritmo percorre o texto e o padrão ao mesmo tempo, se os caracteres forem iguais, avança para o próximo caractere.
Se o padrão for encontrado, adiciona a posição do texto onde o padrão foi encontrado.
Se os caracteres forem diferentes, o algoritmo atualiza o índice do padrão de acordo com o vetor lps.
O algoritmo tem complexidade O(n + m), onde n é o tamanho do texto e m é o tamanho do padrão.
*/

/* Implementação GEEKFORGEEKS*/

void computeLPSArray(string &pat, int M, vector<int> lps){ // pat é o padrão, M é o tamanho do padrão, lps é o vetor que armazenará o tamanho do maior prefixo que é sufixo
    int len = 0; // tamanho do prefixo que é igual ao sufixo
    lps[0] = 0; // lps[0] é sempre 0
    int i = 1; // i é o indice que percorre o vetor
    while(i < M){ // enquanto não percorrer todo o vetor 
        if(pat[i] == pat[len]){ // se o caractere atual for igual ao caractere do prefixo que é sufixo
            len++; // aumenta o tamanho do prefixo que é sufixo
            lps[i] = len; // o tamanho do prefixo que é sufixo é igual a len
            i++; // avança para o próximo caractere
        }else{ // se os caracteres forem diferentes
            if(len != 0){ // se o tamanho do prefixo que é sufixo for diferente de 0
                len = lps[len - 1]; // o tamanho do prefixo que é sufixo é igual ao tamanho do prefixo que é sufixo do caractere anterior
            }else{ // se o tamanho do prefixo que é sufixo for 0
                lps[i] = 0; // o tamanho do prefixo que é sufixo é 0
                i++; // avança para o próximo caractere
            }
        }
    }
}

vector<int> KMP(string &pat, string &txt){
    int m = pat.size(); // tamanho do padrão
    int n = txt.size(); // tamanho do texto
    vector<int>lps(m); // vetor que armazenará o tamanho do maior prefixo que é sufixo
    vector<int>ans; // vetor que armazenará as posições do texto onde o padrão foi encontrado
    computeLPSArray(pat, m, lps); // chama a função que calcula o vetor lps

    int i = 0; // indice que percorre o texto
    int j = 0; // indice que percorre o padrão
    while(i < n){ // enquanto não percorrer todo o texto
        if(pat[j] == txt[i]){ // se o caractere do padrão for igual ao caractere do texto
            i++; // avança para o próximo caractere do texto
            j++; // avança para o próximo caractere do padrão
        }
        if(j == m){ // se j for igual ao tamanho do padrão
            ans.pb(i - j); // adiciona a posição do texto onde o padrão foi encontrado
            j = lps[j - 1]; // j é igual ao tamanho do prefixo que é sufixo do caractere anterior
        }else if(i < n && pat[j] != txt[i]){ // se i for menor que o tamanho do texto e os caracteres forem diferentes
            if(j != 0){ // se j for diferente de 0
                j = lps[j - 1]; // j é igual ao tamanho do prefixo que é sufixo do caractere anterior
            }else{ // se j for igual a 0
                i++; // avança para o próximo caractere do texto
            }
        }
    }
    return ans; // retorna o vetor com as posições do texto onde o padrão foi encontrado
}


/* Implementação do CP-Algorithms*/

vector<int> prefix_function(string &s){
    int n = s.size(); // tamanho da string
    vector<int>pi(n); // vetor que armazenará o tamanho do maior prefixo que é sufixo
    for(int i = 1; i < n; i++){ // percorre a string
        int j = pi[i - 1]; // j é o tamanho do prefixo que é sufixo do caractere anterior
        while(j > 0 && s[i] != s[j]){ // enquanto j for maior que 0 e os caracteres forem diferentes
            j = pi[j - 1]; // j é igual ao tamanho do prefixo que é sufixo do caractere anterior
        }
        if(s[i] == s[j]){ // se os caracteres forem iguais
            j++; // aumenta o tamanho do prefixo que é sufixo
        }
        pi[i] = j; // o tamanho do prefixo que é sufixo é igual a j
    }
    return pi; // retorna o vetor com o tamanho do maior prefixo que é sufixo
}

vector<int> KMP(string &pat, string &txt){
    string s = pat + "#" + txt; // concatena o padrão com o texto
    vector<int>pi = prefix_function(s); // chama a função que calcula o vetor pi
    vector<int>ans; // vetor que armazenará as posições do texto onde o padrão foi encontrado
    for(int i = pat.size() + 1; i < s.size(); i++){ // percorre a string
        if(pi[i] == pat.size()){ // se o tamanho do prefixo que é sufixo for igual ao tamanho do padrão
            ans.pb(i - 2 * pat.size()); // adiciona a posição do texto onde o padrão foi encontrado
        }
    }
    return ans; // retorna o vetor com as posições do texto onde o padrão foi encontrado
}


/* Implementação aula UNESP */

int prefix[1000000], n, m;
char S[1000000], P[1000000];

void calculatePrefix(){
    int i = 0, j = -1;
    prefix[0] = -1;
    while(i < m){
        while(j >= 0 && P[i] != P[j]) // enquanto j for maior ou igual a 0 e os caracteres forem diferentes
            j = prefix[j]; // j é igual ao valor do prefixo do caractere anterior
        i++; j++; // avança para o próximo caractere
        prefix[i] = j; // o valor do prefixo é igual a j
    }
}

vector<int>KMP(){
    vector<int> ans;
    int i = 0, j = 0;
    calculatePrefix();
    while(i < n){
        while(j >=0 && S[i] != P[j]) // enquanto j for maior ou igual a 0 e os caracteres forem diferentes
            j = prefix[j]; // j é igual ao valor do prefixo do caractere anterior
        i++; j++; // avança para o próximo caractere
        if(j == m){ // se j for igual ao tamanho do padrão
            ans.pb(i - j); // adiciona a posição do texto onde o padrão foi encontrado
            j = prefix[j]; // j é igual ao valor do prefixo do caractere anterior
        }
    }

}

int main(){
    fastio;



    return 0;
}