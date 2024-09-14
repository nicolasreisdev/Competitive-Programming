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
A Sparse Table é uma estrutura de dados que permite responder a consultas em intervalos (range queries)
A maioria das queries são realizadas em complexidade O(log(n)), porém, para certos problemas, como a RMQ(Range Minimun Query), a
resposta pode ser calculada em tempo O(1).
Desvantagem: essa estrutura só pode ser usada em arrays imutáveis.
Qualquer alteração implica na reconstrução da Sparse Table: O(n*log(n))
*/

/*
Implementação UNESP
*/

// Pré-computação da Sparse Table
const int K = 20; // log2(10^5)
int st[100000][K+1]; // st[i][j] armazena o índice do menor elemento no intervalo [i, i + 2^j - 1]

int f(int x){
    return x;
}
int f(int x, int y){
    return min(x, y); // RMQ (Range Minimun Query), pode ser mudado para outros tipos de queries
}

void buildSparseTable(vector<int> v, int n){
    for(int i = 0; i < n;i++){
        st[i][0] = f(v[i]);
    }
    for(int j = 1; j <= K; j++){
        for(int i = 0; i + (1 << j) <= n; i++){
            st[i][j] = f(st[i][j-1], st[i + (1 << (j-1))][j-1]);
        }   
    }
}

// Consultas O(log(n))

int elem_neutroRMQ = MAX; // elemento neutro da função f (para RMQ é o maior valor possível)
int elem_neutroSum = 0; // elemento neutro da função f (para soma é 0)

int query(int L, int R){
    int acc = elem_neutroRMQ; // valor neutro da função f
    for(int j = K; j >= 0; j--){ // para cada potência de 2
        if((1 << j) <= R - L + 1){ // se a potência de 2 for menor ou igual ao intervalo
            acc = f(acc, st[L][j]); // atualiza o valor da query
            L += 1 << j; // atualiza o índice
        }
    }
    return acc; 
}

int query(int L, int R){
    int acc = elem_neutroSum; // valor neutro da função f
    for(int j = K; j >= 0; j--){ // para cada potência de 2
        if((1 << j) <= R - L + 1){ // se a potência de 2 for menor ou igual ao intervalo
            acc += st[L][j]; // atualiza o valor da query (soma)
            L += 1 << j; // atualiza o índice
        }
    }
}

// Consultas O(1) (apenas para RMQ)

// Pré-computação dos logs
int logSparseTable[MAX]; // log2[i] armazena o log2 de i

void buildLogs(){
    logSparseTable[1] = 0; // log2(1) = 0
    for(int i = 2; i < MAX; i++){ // para cada número
        logSparseTable[i] = logSparseTable[i/2] + 1; // calcula o log2
    }
}

int query(int L, int R){
    int j = logSparseTable[R - L + 1]; // calcula o log2 do intervalo
    return min(st[L][j], st[R - (1 << j) + 1][j]); // retorna o mínimo entre os dois valores
}



/*
Implementação UFMG
*/

// Sparse Table
//
// Resolve RMQ
// MAX2 = log(MAX)
//
// Complexidades:
// build - O(n log(n))
// query - O(1)

namespace sparse{
    int m[MAX2][MAX], n; 
    void build(int n2, vector<int> v){ // n2 = tamanho do vetor, v = vetor
        n = n2;
        for (int i = 0; i < n; i++)
            m[0][i] = v[i]; // incializa a primeira linha da sparse table com o vetor
        for (int j = 1; (1 << j) <= n; j++) // para cada linha da sparse table
            for (int i = 0; i + (1 << j) <= n; i++) // para cada elemento da linha
                m[j][i] = min(m[j - 1][i], m[j - 1][i + (1 << (j - 1))]); // preenche a sparse table, RMQ (Range Minimun Query)
                // pode ser mudado para outros tipos de queries
    }
    int query(int a, int b){
        int j = __builtin_clz(1) - __builtin_clz(b - a + 1); // builtin_clz = count leading zeros, builtin_ctz = count trailing zeros
        // builtin é uma função intrínseca do GCC que conta os zeros à esquerda ou à direita de um número para 64 bits
        //  com isso conseguimos calcular o log2 de um número
        return min(m[j][a], m[j][b - (1 << j) + 1]); // retorna o mínimo entre os dois valores
    }
}

/*
Implementação CP-Algorithms
*/
int K = 25; // log2(10^6)
int st[K+1][MAX]; // st[i][j] armazena o índice do menor elemento no intervalo [i, i + 2^j - 1]

void buildSparseTable(vector<int> v, int n){

    for (int i = 1; i <= K; i++)
        for (int j = 0; j + (1 << i) <= n; j++)
            st[i][j] = f(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]);
}

int main(){
    fastio;

    return 0;
}