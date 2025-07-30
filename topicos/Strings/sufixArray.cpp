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
O kasai é um algoritmo que calcula o vetor lcp (longest common prefix) de um vetor de sufixos.
O vetor lcp[i] armazena o tamanho do maior prefixo comum entre os sufixos sa[i] e sa[i + 1].

Complexidade:
sufix_array: O(n * log(n))
kasai: O(n)
*/

vector<int> suffix_array(string s){
    s += "$"; // adiciona o caractere que representa o final da string
    int n = s.size(), N = max(n, 256); // n é o tamanho da string, N é o tamanho do alfabeto
    vector<int> sa(n), ra(n); // sa é o vetor que armazenará o suffix array, ra é o vetor que armazenará o rank
    for(int i = 0; i < n; i++){ // inicializa os vetores
        sa[i] = i; //  o suffix array é igual a posição i
        ra[i] = s[i]; // o rank é igual ao caractere da string
    }

    for(int k = 0; k < n; k ? k *= 2 : k++){ // enquanto k for diferente de 0, k é igual a k * 2, senão k é igual a 0
        vector<int> nsa(sa), nra(n), cnt(N); // nsa é o novo suffix array, nra é o novo rank, cnt é o vetor que armazenará a quantidade de caracteres
        for(int i = 0; i < n; i++){ // inicializa o vetor cnt
            nsa[i] = (nsa[i] - k + n) % n; // atualiza o suffix array
            cnt[ra[i]]++; // incrementa a quantidade de caracteres
        }
        for(int i = 1; i < N; i++){ // percorre o vetor cnt
            cnt[i] += cnt[i - 1]; // atualiza a quantidade de caracteres
        }
        for(int i = n - 1; i+1; i--){ // percorre o vetor de trás para frente
            sa[--cnt[ra[nsa[i]]]] = nsa[i]; // atualiza o suffix array (sa na posição cnt[ra[nsa[i]]] é igual a nsa[i])
        }
        for(int i = 1, r = 0; i < n; i++){ // percorre o vetor
            nra[sa[i]] = r += ra[sa[i]] != ra[sa[i-1]] or ra[(sa[i] + k) % n] != ra[(sa[i-1] + k) % n]; // atualiza o rank
        }
        ra = nra; // o rank é igual ao novo rank
        if(ra[sa[n - 1]] == n - 1) break; // se o rank do último elemento do suffix array for igual a n - 1, sai do loop
    }
    return vector<int>(sa.begin() + 1, sa.end()); // retorna o suffix array sem o caractere que representa o final da string
}

vector<int> kasai(string s, vector<int> sa){
    int n = s.size(), k = 0; // n é o tamanho da string, k é o tamanho do prefixo comum
    vector<int> ra(n), lcp(n); // ra é o vetor que armazenará o rank, lcp é o vetor que armazenará o tamanho do maior prefixo comum
    for(int i = 0; i < n; i++){ // inicializa os vetores
        ra[sa[i]] = i; // o rank é igual a i
    }
    for(int i = 0; i < n; i++){ // percorre o vetor
        if(ra[i] == n - 1){ // se o rank for igual a n - 1
            k = 0; // o tamanho do prefixo comum é 0
            continue; // pula para a próxima iteração
        }
        int j = sa[ra[i] + 1]; // j é igual ao próximo sufixo
        while(i + k < n and j + k < n and s[i + k] == s[j + k]){ // enquanto i + k for menor que n, j + k for menor que n e os caracteres forem iguais
            k++; // aumenta o tamanho do prefixo comum
        }
        lcp[ra[i]] = k; // o tamanho do maior prefixo comum é igual a k
        if(k) k--; // se k for diferente de 0, diminui o tamanho do prefixo comum
    }
    return lcp; // retorna o vetor com o tamanho do maior prefixo comum
}


int main(){
    fastio;



    return 0;
}