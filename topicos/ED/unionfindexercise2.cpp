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
const int MAX = 3 * 1e5 + 1; // o valor é triplicado pois faremos 3 conjuntos, 1 de amigos, 1 de predadores e 1 de presas
const int MAX_CONJUNTOS = 50000;
const ll LMAX = 0x3f3f3f3f3f3f3f3f;

int parent[MAX];
int tam[MAX];

void start(){
    for(int i = 1; i < MAX_CONJUNTOS; i++){ // primeiro terço do vetor é de amigos (primeiro conjunto)
        parent[i] = i; // o pai de i é i
        tam[i] = 1; // o tamanho de i é 1
    }
    for(int i = MAX_CONJUNTOS + 1; i < 2 * MAX_CONJUNTOS; i++){ // segundo terço do vetor é de predadores (segundo conjunto)
        parent[i] = -1; // inicializado com -1 pois inicialmente não tem predador
        tam[i] = 0; // não tem tamanho pois não tem predador
    }
    for(int i = 2 * MAX_CONJUNTOS + 1; i < MAX; i++){ // terceiro terço do vetor é de presas (terceiro conjunto)
        parent[i] = -1; // inicializado com -1 pois inicialmente não tem presa
        tam[i] = 0; // não tem tamanho pois não tem presa
    }
}

int find(int x){
    if(parent[x] == x || parent[x] == -1){ // se x é o pai de x ou x é -1
        return x;
    }
    return parent[x] = find(parent[x]); // path compression
}

bool same(int x, int y){
    return find(x) == find(y);
}

void merge(int x, int y){
    int a = find(x); // pai de x
    int b = find(y); // pai de y
    if(a == b) return; // se já são do mesmo grupo
    if(tam[a] < tam[b]) swap(a, b); // se o tamanho de a é menor que o tamanho de b, troca a e b
    parent[b] = a; // b é filho de a
    tam[a] += tam[b]; // o tamanho de a é incrementado pelo tamanho de b
}

int presa(int x){
    return 2 * MAX_CONJUNTOS + x; // retorna a presa de x
}

int predador(int x){
    return MAX_CONJUNTOS + x; // retorna o predador de x
}

int main(){
    fastio;

    return 0;
}